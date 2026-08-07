#include "screens.h"
#include "display.h"
#include "heure.h"
#include "meteo.h"
#include "config.h"


void drawTitle(
    String title
)
{
    tft.setTextDatum(MC_DATUM);

    tft.setTextFont(2);

    tft.setTextColor(
        TFT_CYAN,
        TFT_BLACK
    );

    tft.drawString(
        title,
        SCREEN_WIDTH/2,
        TITLE_Y,
        2
    );

    tft.drawFastHLine(
        0,
        TITLE_LINE_Y,
        SCREEN_WIDTH,
        TFT_DARKGREY
    );
}

void updateClockScreen()
{
    drawSystemHeader();

    drawBigClock(
        tft,
        SCREEN_WIDTH / 2,
        125
    );
}

void showClockScreen()
{
    clearScreen();

    drawSystemHeader();

    drawTitle(
        "HORLOGE"
    );

    drawBigClock(
        tft,
        SCREEN_WIDTH/2,
        125
    );
}



void showWeatherScreen()
{
    clearScreen();

    drawSystemHeader();

    drawTitle(
        "METEO"
    );

    drawWeather();
}