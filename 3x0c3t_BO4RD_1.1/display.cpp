#include "display.h"
#include "config.h"
#include "progress.h"
#include "heure.h"

TFT_eSPI tft = TFT_eSPI();

void displayInit()
{
    tft.init();
    tft.setRotation(TFT_ROTATION);
    clearScreen();
}

void clearScreen()
{
    tft.fillScreen(COLOR_BACKGROUND);
}

void centerText(String txt,int y,uint8_t font,uint16_t color)
{
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(color,COLOR_BACKGROUND);
    tft.drawString(txt,SCREEN_WIDTH/2,y,font);
}

void drawSystemHeader()
{
    drawProgress(100);

    drawHeaderClock(
        tft,
        SCREEN_WIDTH/2,
        HEADER_Y
    );

    tft.drawFastHLine(
        0,
        HEADER_LINE_Y,
        SCREEN_WIDTH,
        TFT_DARKGREY
    );
}