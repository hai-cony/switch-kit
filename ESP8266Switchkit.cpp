#include "ESP8266Switchkit.h"
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

unsigned long lastTime = 0;

String ESP8266Switchkit::startConnection(String ssid, String password)
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.printf("SSID : %s\n", ssid);
    Serial.printf("Password : %s\n", password);
    Serial.println("Connecting");

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }

    Serial.println("");
    Serial.println(WiFi.macAddress());
    Serial.println(String(ESP.getChipId()));
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());

    for (uint8_t t = 3; t > 0; t--)
    {
      Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
      delay(1000);
    }
  }
  Serial.println("[SETUP] DEVICE READY");

  return "[SETUP] NODEMCU DEVICE READY";
}

String ESP8266Switchkit::fetch(String apikey){
  String obj;

  if (WiFi.status() == WL_CONNECTED && (millis() - lastTime) > 10000)
  {
    std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);

    client->setInsecure();

    HTTPClient https;

    // Your Domain name with URL path or IP address with path
    https.begin(*client, "https://express-for-vercel-eight.vercel.app/esp/fetcher");

    https.addHeader("Content-Type", "application/json");

    // parsing JSON for send request
    DynamicJsonDocument doc(2048);
    
    doc["apikey"] = apikey;
    doc["chip_id"] = String(ESP.getChipId());
    doc["mac"] = WiFi.macAddress();

    // Serialize JSON document
    String json;
    serializeJson(doc, json);

    // Send HTTP POST request
    int httpResponseCode = https.POST(json);

    if (httpResponseCode == 200)
    {
      String payload = https.getString();
      obj = payload;
    }
    else
    {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
      Serial.println("Fetching error");
      // return "Error code : " + httpResponseCode;
    }

    lastTime = millis();
  }
  else
  {
    if ((millis() - lastTime) > 10000)
    {
      lastTime = millis();
    }
    return {};
  }
  return obj;
}
