#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>

extern TFT_eSPI tft;

void displayInit();

void clearScreen();

void centerText(
    String txt,
    int y,
    uint8_t font,
    uint16_t color
);

void drawSystemHeader();

#endif