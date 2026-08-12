#include "page_1.h"
#include "display.h"
#include "settings.h"
#include "header.h"

void page1Draw()
{
    tft.fillRect(
        0,
        CONTENT_Y,
        SCREEN_WIDTH,
        SCREEN_HEIGHT - CONTENT_Y,
        CONTENT_BGC
    );

    header1Draw();
    header2Draw("PAGE 1");

    tft.setTextDatum(MC_DATUM);

    tft.setTextColor(
        TFT_WHITE,
        CONTENT_BGC
    );

    tft.drawString(
        "PAGE 1",
        SCREEN_WIDTH / 2,
        CONTENT_Y + 40
    );

    tft.setTextDatum(TL_DATUM);
}