#ifndef LOGO_H
#define LOGO_H

#include <Arduino.h>
#include <TFT_eSPI.h>


#define LOGO_WIDTH 120
#define LOGO_HEIGHT 26


extern const uint16_t logoBitmap[] PROGMEM;


void drawLogo(
    TFT_eSPI &tft,
    int16_t x,
    int16_t y
);


#endif