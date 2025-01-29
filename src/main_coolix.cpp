#include <Arduino.h>                  // Core Arduino library
#include <arduino_homekit_server.h>   // HomeKit server library
#include <SHTSensor.h>                // SHT temperature and humidity sensor library
#include "wifi_info.h"                // WiFi connection details (SSID and password)
#include <IRsend.h>                   // IR send library
#include <ir_Coolix.h>                // Coolix AC IR protocol library

// Debug logging macro to print file name, function name, and line number
#define LOG_PRINT(fmt, args...) printf(("%s,%s,LINE%d: " fmt "\n"), __FILE__, __func__, __LINE__, ##args)

// Sensor calibration offsets
#define SENSOR_TEMP_OFFSET 0.0        // Temperature calibration offset
#define SENSOR_HUM_OFFSET 0.0         // Humidity calibration offset

// Pin definitions
#define IR_TX_PIN 14                  // IR transmitter pin
#define LED_PIN 2                     // LED indicator pin

// Function prototypes
void setupHomeKit();                  // Initialize HomeKit
void loopHomeKit();                   // HomeKit main loop
void updateACStatus();                // Update AC status
void readSensorData();                // Read sensor data
void sendIRCommand();                 // Send IR command
void handleWiFiConnection();          // Handle WiFi connection

// Initialize Coolix AC IR control object
IRCoolixAC ac(IR_TX_PIN);

// Global variables
bool shouldSendIRCommand = false;     // Flag to indicate if an IR command should be sent
SHTSensor sht;                        // SHT temperature and humidity sensor object

// HomeKit characteristic declarations
extern "C" homekit_server_config_t config;                          // HomeKit server configuration
extern "C" homekit_characteristic_t ac_name;                        // AC name
extern "C" homekit_characteristic_t ac_active;                      // AC power state
extern "C" homekit_characteristic_t current_temperature;            // Current temperature
extern "C" homekit_characteristic_t current_relative_humidity;      // Current humidity
extern "C" homekit_characteristic_t target_heater_cooler_state;     // Target heating/cooling state
extern "C" homekit_characteristic_t cooling_threshold_temperature;  // Cooling target temperature
extern "C" homekit_characteristic_t rotation_speed;                 // Fan speed
extern "C" homekit_characteristic_t swing_mode;                     // Swing mode

// Initialize LED
void initLED() {
    pinMode(LED_PIN, OUTPUT);         // Set LED pin as output
    digitalWrite(LED_PIN, LOW);       // Turn off LED initially
}

// Setup function
void setup() {
    Serial.begin(115200);             // Initialize serial communication at 115200 baud rate
    while (!Serial) delay(50);        // Wait for serial connection

    initLED();                        // Initialize LED
    handleWiFiConnection();           // Connect to WiFi

    Wire.begin(4, 5);                 // Initialize I2C communication (SDA=4, SCL=5)
    if (!sht.init()) {                // Initialize SHT sensor
        LOG_PRINT("Failed to initialize SHT sensor!");
    }
    sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); // Set sensor accuracy to medium

    ac.begin();                       // Initialize IR control
    setupHomeKit();                   // Initialize HomeKit

    WiFi.setSleepMode(WIFI_LIGHT_SLEEP); // Set WiFi to light sleep mode for power saving
}

// Main loop
void loop() {
    loopHomeKit();                    // Handle HomeKit events
    delay(10);                        // Short delay

    if (shouldSendIRCommand) {        // If an IR command needs to be sent
        sendIRCommand();              // Send IR command
        shouldSendIRCommand = false;  // Reset the flag
    }
}

// Read sensor data (temperature and humidity)
void readSensorData() {
    if (sht.readSample()) {           // If sensor data is successfully read
        float temperature = sht.getTemperature() + SENSOR_TEMP_OFFSET; // Read temperature and apply offset
        float humidity = sht.getHumidity() + SENSOR_HUM_OFFSET;        // Read humidity and apply offset

        // If temperature or humidity has changed, update HomeKit characteristics and notify clients
        if (temperature != current_temperature.value.float_value || humidity != current_relative_humidity.value.float_value) {
            current_temperature.value = HOMEKIT_FLOAT(temperature);
            current_relative_humidity.value = HOMEKIT_FLOAT(humidity);
            homekit_characteristic_notify(&current_temperature, current_temperature.value);
            homekit_characteristic_notify(&current_relative_humidity, current_relative_humidity.value);
        }
    } else {
        LOG_PRINT("Failed to read sensor data!"); // Log error if reading fails
    }
}

// Send IR command
void sendIRCommand() {
    LOG_PRINT("Sending IR command..."); // Log the action
    ac.send();                         // Send IR command
}

// Update AC status
void updateACStatus() {
    if (ac_active.value.bool_value) {  // If AC is turned on
        ac.on();                       // Turn on AC
        ac.setMode(ac.convertMode(stdAc::opmode_t::kCool)); // Set to cooling mode
        ac.setTemp(cooling_threshold_temperature.value.float_value); // Set target temperature
    } else {
        ac.off();                      // Turn off AC
    }
    shouldSendIRCommand = true;        // Set flag to send IR command
}

// Initialize HomeKit
void setupHomeKit() {
    // Set callback for AC power state
    ac_active.setter = [](const homekit_value_t value) {
        ac_active.value.bool_value = value.bool_value;
        updateACStatus();              // Update AC status
    };

    // Set callback for target temperature
    cooling_threshold_temperature.setter = [](const homekit_value_t value) {
        cooling_threshold_temperature.value = HOMEKIT_FLOAT(value.float_value);
        updateACStatus();              // Update AC status
    };

    // Set callback for fan speed
    rotation_speed.setter = [](const homekit_value_t value) {
        uint8_t speed = (uint8_t)(value.float_value / 20); // Convert HomeKit value to fan speed
        rotation_speed.value = HOMEKIT_FLOAT(speed * 20);
        ac.setFan(ac.convertFan(static_cast<stdAc::fanspeed_t>(speed))); // Set fan speed
        shouldSendIRCommand = true;    // Set flag to send IR command
    };

    // Set callback for swing mode
    swing_mode.setter = [](const homekit_value_t value) {
        swing_mode.value = HOMEKIT_UINT8(value.uint8_value);
        ac.setSwing(value.uint8_value); // Set swing mode
        shouldSendIRCommand = true;    // Set flag to send IR command
    };

    // Generate unique device name and serial number from MAC address
    uint8_t mac[6];
    WiFi.macAddress(mac);
    sprintf(ac_name.value.string_value, "HAC-%02X%02X%02X", mac[3], mac[4], mac[5]);
    sprintf(serial_number.value.string_value, "%02X%02X%02X%02X%02X%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    accessory_init();                  // Initialize HomeKit accessory
    arduino_homekit_setup(&config);    // Start HomeKit server
}

// HomeKit main loop
void loopHomeKit() {
    arduino_homekit_loop();            // Handle HomeKit events

    static uint32_t lastSensorReadTime = 0;
    if (millis() - lastSensorReadTime > 30000) { // Read sensor data every 30 seconds
        lastSensorReadTime = millis();
        readSensorData();
    }

    static uint32_t lastHeapInfoTime = 0;
    if (millis() - lastHeapInfoTime > 15000) { // Log heap memory info every 15 seconds
        lastHeapInfoTime = millis();
        LOG_PRINT("Free heap: %d, HomeKit clients: %d", ESP.getFreeHeap(), arduino_homekit_connected_clients_count());
    }
}

// Handle WiFi connection
void handleWiFiConnection() {
    wifi_connect();                    // Connect to WiFi
    if (WiFi.status() != WL_CONNECTED) {
        LOG_PRINT("Failed to connect to WiFi!"); // Log error if connection fails
    }
}
