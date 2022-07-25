#ifndef _WIFI_INFO_H_
#define _WIFI_INFO_H_

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

const char *ssid = "mywifissid";
const char *password = "mypassword ";

void wifi_connect() {
    WiFi.persistent(false);
    WiFi.mode(WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(ssid, password);
    Serial.println("WiFi connecting...");
    while (!WiFi.isConnected()) {
        delay(10); 
        Serial.print(".");        
    }
    Serial.println();
}

#endif /* _WIFI_INFO_H_ */