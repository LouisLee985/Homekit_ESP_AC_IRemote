#ifndef _WIFI_INFO_H_
#define _WIFI_INFO_H_

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#endif

const char *ssid = "mywifissid";
const char *password = "mypassword ";

void wifi_connect()
{
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(ssid, password);
  Serial.println("WiFi connecting...");
  while (!WiFi.isConnected())
  {
    delay(50);
    Serial.print(".");
  }
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
