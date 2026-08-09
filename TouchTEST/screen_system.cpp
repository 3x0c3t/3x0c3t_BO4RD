#include "screen_system.h"

#include "config.h"
#include "display.h"
#include "ui.h"


void screenSystem()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );


    drawHeader();


    tft.setTextColor(
        COLOR_PRIMARY,
        COLOR_BACKGROUND
    );

    tft.setTextSize(
        2
    );

    tft.setCursor(
        10,
        80
    );

    tft.println(
        "SYSTEME"
    );


    tft.setTextColor(
        COLOR_TEXT,
        COLOR_BACKGROUND
    );

    tft.setTextSize(
        1
    );

    tft.setCursor(
        10,
        110
    );

    tft.println(
        "Informations systeme"
    );


    drawFooter();
}