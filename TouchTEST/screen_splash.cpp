#include "screen_splash.h"

#include <TFT_eSPI.h>

#include "display.h"

void screenSplash()
{
    tft.fillScreen(
        TFT_BLACK
    );

    tft.setTextColor(
        TFT_CYAN,
        TFT_BLACK
    );

    tft.setTextSize(3);

    tft.setCursor(
        35,
        145
    );

    tft.print(
        "-3xØc3t-"
    );
}