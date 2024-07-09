#ifndef ES8266SWITCHKIT_H
#define ES8266SWITCHKIT_H

#include <Arduino.h>

class ESP8266Switchkit {
  public: 
    String startConnection(String ssid, String password);
    String fetch(String token, String url);
};

#endif