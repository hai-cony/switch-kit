// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266HTTPClient.h>
// #include <WiFiClientSecureBearSSL.h>
// #include <WiFiClient.h>
// #include <ArduinoJson.h>
// #include "ESP8266Switchkit.h"

// ESP8266Switchkit ESkit;

// // unsigned long lastTime = 0;

// String url = "https://express-for-vercel-eight.vercel.app/login";
// String apikey = "820f9bf98732ded39d5306ee28e6cb68ee3b7ae97420a18bdc9667633d70861c5dfbf9aa675bdc6045fabf8aa2bc2761";

// // void startConnection(String ssid, String password){
// //   if (WiFi.status() != WL_CONNECTED)
// //   {
// //     Serial.printf("SSID : %s\n", ssid);
// //     Serial.printf("Password : %s\n", password);
// //     Serial.println("Connecting");

// //     WiFi.mode(WIFI_STA);
// //     WiFi.begin(ssid, password);

// //     while (WiFi.status() != WL_CONNECTED)
// //     {
// //       delay(500);
// //       Serial.print(".");
// //     }

// //     Serial.println("");
// //     Serial.println(WiFi.macAddress());
// //     Serial.println(String(ESP.getChipId()));
// //     Serial.print("Connected to WiFi network with IP Address: ");
// //     Serial.println(WiFi.localIP());

// //     for (uint8_t t = 3; t > 0; t--)
// //     {
// //       Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
// //       delay(1000);
// //     }

// //   }
// // }

// // String fetch(String apikey, String url){
// //   String obj;
// //   if (WiFi.status() == WL_CONNECTED && (millis() - lastTime) > 5000)
// //   {
// //     std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);

// //     // client->setFingerprint(fingerprint);
// //     client->setInsecure();

// //     HTTPClient https;

// //     // Your Domain name with URL path or IP address with path
// //     https.begin(*client, url);

// //     https.addHeader("Content-Type", "application/json");

// //     // parsing JSON for send request
// //     DynamicJsonDocument doc(2048);
    
// //     doc["apikey"] = apikey;
// //     doc["chip_id"] = String(ESP.getChipId());
// //     doc["mac"] = WiFi.macAddress();

// //     // Serialize JSON document
// //     String json;
// //     serializeJson(doc, json);

// //     // Send HTTP POST request
// //     int httpResponseCode = https.POST(json);

// //     if (httpResponseCode == 200)
// //     {
// //       String payload = https.getString();
// //       obj = payload;
// //     }
// //     else
// //     {
// //       Serial.print("Error code: ");
// //       Serial.println(httpResponseCode);
// //       Serial.println("Fetching error");
// //     }

// //     lastTime = millis();
// //   }
// //   else
// //   {
// //     if ((millis() - lastTime) > 5000)
// //     {
// //       lastTime = millis();
// //     }
// //     return {};
// //   }
// //   return obj;
// // }

// // ================================ YOUR CODE ===================================
// void setup() {
//   Serial.begin(115200);  // For Debug
//   ESkit.startConnection("Ollamart", "keluargaolla");
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   String response = ESkit.fetch(apikey, url);

//   DynamicJsonDocument doc(2048);

//   // // Check value of json
//   if(response.length() > 1){
//     // Do whatever with response from web    
//     Serial.println(response);
//     StaticJsonDocument<512> jsonBuffer;
//     deserializeJson(doc, response);
//     // Serial.println(doc);
//     // get data from buffer doc["name_id"];
//     // the values ​​must be the same as those on the web name ID at controller's page
//     // String locked = doc["door_lock"];
//     // // Do whatever with response value
//     // if (!locked || locked == "null"){
//     //   Serial.println("Failed to get response from the server.");
//     //   return;
//     // }
//   }
// }

#include <Arduino.h>
#include <ESP8266WiFi.h>

void setup(){
    Serial.begin(115200);
    Serial.println("\nALAMAT MAC : " + WiFi.macAddress());
    Serial.println("ID CHIP : " + String(ESP.getChipId()));
}

void loop(){}