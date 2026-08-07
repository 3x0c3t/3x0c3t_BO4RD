#ifndef HEURE_H
#define HEURE_H

#include <TFT_eSPI.h>

void initClock();

void drawHeaderClock(
    TFT_eSPI &tft,
    int16_t x,
    int16_t y
);

void drawBigClock(
    TFT_eSPI &tft,
    int16_t x,
    int16_t y
);

#endif