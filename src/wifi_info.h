#ifndef _WIFI_INFO_H_
#define _WIFI_INFO_H_

#include <Arduino.h>
#include <stdio.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

const char *ssid = "mywifissid";
const char *password = "mypassword ";

#define LED_PIN 2
extern void Led_int();

static uint32_t previousledMillis = 0; 
void blinkled(uint32_t interval){
    const uint32_t currentMillis = millis();
    if (currentMillis - previousledMillis >= interval) {
        previousledMillis = currentMillis;
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    } else if (currentMillis - previousledMillis <= 0) {   // if millis overflow (go back to zero), after approximately 50 days.
        previousledMillis = currentMillis;
    }
}


void wifi_connect()
{
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(ssid, password);
  Serial.println("WiFi connecting...");
  while (!WiFi.isConnected())
  {
    blinkled(200);
    delay(50);
    Serial.print(".");
  }
  Led_int();
  Serial.print("\n");
  // Serial.printf("WiFi connected, IP: %s\n", WiFi.localIP().toString().c_str());
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID()); // WiFi
  Serial.print("IP :\t");
  Serial.println(WiFi.localIP()); // IP
  Serial.print("MAC :\t");
  Serial.println(WiFi.macAddress());
}
#endif /* _WIFI_INFO_H_ */
