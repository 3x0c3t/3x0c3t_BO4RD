#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>

void wifiInit();

bool wifiConnected();

String wifiSSID();

String wifiIP();

String wifiMAC();

int wifiRSSI();

String wifiStatus();

#endif