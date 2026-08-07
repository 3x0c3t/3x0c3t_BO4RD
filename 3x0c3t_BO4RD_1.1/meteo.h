#ifndef METEO_H
#define METEO_H

#include <Arduino.h>
#include <TFT_eSPI.h>

extern float temperature;
extern float feelsLike;
extern float tempMin;
extern float tempMax;

extern int humidity;
extern int pressure;

extern String weatherDescription;

extern String sunrise;
extern String sunset;
extern String lastUpdate;

void initWeather();
void updateWeather();
void drawWeather();

#endif