
#include <homekit/homekit.h>
#include <homekit/characteristics.h>
#include <homekit/types.h>

#include "accessory.h"

#define LOG_PRINT(fmt,args...)      printf(("%s,%s,LINE%d: " fmt "\n"),__FILE__,__func__,__LINE__, ##args)
#define ACCESSORY_NAME              ("HAC-Remote")
#define OPTIONAL_NAME               ("Humidity")
#define ACCESSORY_SN                ("211985")      //SERIAL_NUMBER
#define ACCESSORY_MANUFACTURER      ("Louis Lee")
#define ACCESSORY_MODEL             ("ESP8266")
#define ACCESSORY_FIRMWARE_REVISION ("1.03")
#define ACCESSORY_HARDWARE_REVISION ("202205")


// char serial[16] = "XXXXXX\0";
homekit_characteristic_t ac_name           = HOMEKIT_CHARACTERISTIC_(NAME, ACCESSORY_NAME);
homekit_characteristic_t optional_name     = HOMEKIT_CHARACTERISTIC_(NAME, OPTIONAL_NAME);
homekit_characteristic_t ac_active         = HOMEKIT_CHARACTERISTIC_(ACTIVE, 0);
homekit_characteristic_t current_temperature = HOMEKIT_CHARACTERISTIC_(CURRENT_TEMPERATURE, 0,
        .min_value = (float[]) {-40},
        .max_value = (float[]) {125}
        );

homekit_characteristic_t current_relative_humidity      = HOMEKIT_CHARACTERISTIC_(CURRENT_RELATIVE_HUMIDITY, 0);

//INACTIVE=0, IDLE=1, HEATING=2, COOLING=3
homekit_characteristic_t current_heater_cooler_state    = HOMEKIT_CHARACTERISTIC_(CURRENT_HEATER_COOLER_STATE, 0,
        .valid_values={.count=4, .values = (uint8_t[]) {0, 1, 2,3}}
        );

//0=AUTO, 1=HEAT, 2=COOL 
homekit_characteristic_t target_heater_cooler_state     = HOMEKIT_CHARACTERISTIC_(TARGET_HEATER_COOLER_STATE, 2,
        .valid_values={.count=1, .values=(uint8_t[]) {2}},
        );

homekit_characteristic_t cooling_threshold_temperature  = HOMEKIT_CHARACTERISTIC_(COOLING_THRESHOLD_TEMPERATURE, 26, 
        .min_value  =(float[]) {17}, 
        .max_value  =(float[]) {30},
        .min_step   =(float[]) {1.0}
        );

homekit_characteristic_t rotation_speed    = HOMEKIT_CHARACTERISTIC_(ROTATION_SPEED, 0,        
        .min_step   =(float[]) {10}
        );

homekit_characteristic_t swing_mode = HOMEKIT_CHARACTERISTIC_(SWING_MODE, 0);

homekit_characteristic_t serial_number = HOMEKIT_CHARACTERISTIC_(SERIAL_NUMBER, ACCESSORY_SN);

void accessory_identify(homekit_value_t _value) {
	LOG_PRINT("accessory identify\n");        
}

homekit_accessory_t *accessories[] ={
        HOMEKIT_ACCESSORY(.id = 1, .category = homekit_accessory_category_air_conditioner, .services=(homekit_service_t*[]){
                HOMEKIT_SERVICE(ACCESSORY_INFORMATION, .characteristics=(homekit_characteristic_t*[]){
                        HOMEKIT_CHARACTERISTIC(IDENTIFY, accessory_identify),
                        HOMEKIT_CHARACTERISTIC(MANUFACTURER, ACCESSORY_MANUFACTURER),
                        HOMEKIT_CHARACTERISTIC(MODEL, ACCESSORY_MODEL),
                        &ac_name,
                        // HOMEKIT_CHARACTERISTIC(SERIAL_NUMBER, ACCESSORY_SN),
                        &serial_number,
                        HOMEKIT_CHARACTERISTIC(FIRMWARE_REVISION, ACCESSORY_FIRMWARE_REVISION),
                        NULL
                }),
                HOMEKIT_SERVICE(HEATER_COOLER, .primary=true, .characteristics=(homekit_characteristic_t*[]){
                //Required Characteristics:
                        &ac_active,
                        &current_temperature,
                        &current_heater_cooler_state,
                        &target_heater_cooler_state,
                // Optional Characteristics:
                        // &optional_name,
                        &rotation_speed,
			&swing_mode,
			// &current_relative_humidity,
                        &cooling_threshold_temperature,
                NULL
                }),
                HOMEKIT_SERVICE(HUMIDITY_SENSOR, .primary=false, .characteristics=(homekit_characteristic_t*[]) {
			&current_relative_humidity,
		NULL
		}),
                
        NULL
        }),
NULL
};


homekit_server_config_t config = {
        .accessories = accessories,
        .password = "111-11-111",
        .setupId = "ABC8"
};


void accessory_init() {
	ac_active.value=HOMEKIT_UINT8(0);
}
