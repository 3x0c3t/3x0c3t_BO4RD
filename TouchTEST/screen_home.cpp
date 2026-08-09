#include "screen_home.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "ui.h"
#include "screens.h"

// =====================================================
// HOME
// =====================================================

void screenHome()
{
    tft.fillScreen(
        TFT_BLACK
    );

    drawHeader();

    tft.setTextColor(
        TFT_WHITE,
        TFT_BLACK
    );

    tft.setTextSize(2);

    tft.setCursor(
        60,
        120
    );

    tft.print(
        "INTERFACE"
    );

    drawFooter();
}

// =====================================================
// TOUCH HOME
// =====================================================

void homeHandleTouch(
    int16_t x,
    int16_t y
)
{
    Serial.print(
        "HOME TOUCH X="
    );

    Serial.print(x);

    Serial.print(
        " Y="
    );

    Serial.println(y);
}