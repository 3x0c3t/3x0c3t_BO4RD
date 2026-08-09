#include "display.h"

TFT_eSPI tft = TFT_eSPI();

void displayInit()
{
    tft.init();

    tft.setRotation(
        TFT_ROTATION
    );

    tft.fillScreen(
        TFT_BLACK
    );
}