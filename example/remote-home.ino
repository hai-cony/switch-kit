#include <Arduino.h>
#include <ESP8266WiFi.h>

void setup(){
    Serial.begin(115200);
    Serial.println("\nALAMAT MAC : " + WiFi.macAddress());
    Serial.println("ID CHIP : " + String(ESP.getChipId()));
}

void loop(){}
