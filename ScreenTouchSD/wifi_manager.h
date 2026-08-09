#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <Arduino.h>

bool wifiConnect();

bool wifiIsConnected();

String wifiGetIP();

int wifiGetRSSI();

#endif