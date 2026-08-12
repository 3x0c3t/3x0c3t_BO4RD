#include "header.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "settings.h"

// H1
void header1Draw()
{
    // H1B1
    tft.fillRect(
        H1B1_X,
        H1B1_Y,
        H1B1_W,
        H1B1_H,
        H1B1_BGC
    );

    tft.drawRect(
        H1B1_X,
        H1B1_Y,
        H1B1_W,
        H1B1_H,
        H1B1_BC
    );

    tft.setTextSize(H1B1_TEXT_SIZE);
    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(
        H1B1_TC,
        H1B1_BGC
    );

    tft.drawString(
        "12:34:56",
        H1B1_X + H1B1_W / 2,
        H1B1_Y + H1B1_H / 2
    );

    // H1B2
    tft.fillRect(
        H1B2_X,
        H1B2_Y,
        H1B2_W,
        H1B2_H,
        H1B2_BGC
    );

    tft.drawRect(
        H1B2_X,
        H1B2_Y,
        H1B2_W,
        H1B2_H,
        H1B2_BC
    );

    tft.setTextSize(H1B2_TEXT_SIZE);
    tft.setTextColor(
        H1B2_TC,
        H1B2_BGC
    );

    tft.drawString(
        "2026/08/12",
        H1B2_X + H1B2_W / 2,
        H1B2_Y + H1B2_H / 2
    );

    // H1B3
    tft.fillRect(
        H1B3_X,
        H1B3_Y,
        H1B3_W,
        H1B3_H,
        H1B3_BGC
    );

    tft.drawRect(
        H1B3_X,
        H1B3_Y,
        H1B3_W,
        H1B3_H,
        H1B3_BC
    );

    tft.setTextSize(H1B3_TEXT_SIZE);
    tft.setTextColor(
        H1B3_TC,
        H1B3_BGC
    );

    tft.drawString(
        "-3X0C3T-",
        H1B3_X + H1B3_W / 2,
        H1B3_Y + H1B3_H / 2
    );

    // H1B4
    tft.fillRect(
        H1B4_X,
        H1B4_Y,
        H1B4_W,
        H1B4_H,
        H1B4_BGC
    );

    tft.drawRect(
        H1B4_X,
        H1B4_Y,
        H1B4_W,
        H1B4_H,
        H1B4_BC
    );

    // H1B5
    tft.fillRect(
        H1B5_X,
        H1B5_Y,
        H1B5_W,
        H1B5_H,
        H1B5_BGC
    );

    tft.drawRect(
        H1B5_X,
        H1B5_Y,
        H1B5_W,
        H1B5_H,
        H1B5_BC
    );

    tft.setTextDatum(TL_DATUM);
}

// H2
void header2Draw(const char *title)
{
    // H2 fond
    tft.fillRect(
        0,
        H2_Y,
        SCREEN_WIDTH,
        H2_H,
        TFT_BLACK
    );

    // H2B1
    tft.fillRect(
        H2B1_X,
        H2B1_Y,
        H2B1_W,
        H2B1_H,
        H2B1_BGC
    );

    tft.drawRect(
        H2B1_X,
        H2B1_Y,
        H2B1_W,
        H2B1_H,
        H2B1_BC
    );

    tft.setTextDatum(MC_DATUM);
    tft.setTextColor(
        H2B1_TC,
        H2B1_BGC
    );

    tft.drawString(
        "MENU",
        H2B1_X + H2B1_W / 2,
        H2B1_Y + H2B1_H / 2
    );

    // H2B2
    tft.fillRect(
        H2B2_X,
        H2B2_Y,
        H2B2_W,
        H2B2_H,
        H2B2_BGC
    );

    tft.drawRect(
        H2B2_X,
        H2B2_Y,
        H2B2_W,
        H2B2_H,
        H2B2_BC
    );

    tft.setTextColor(
        H2B2_TC,
        H2B2_BGC
    );

    tft.drawString(
        title,
        H2B2_X + H2B2_W / 2,
        H2B2_Y + H2B2_H / 2
    );

    // H2B3
    tft.fillRect(
        H2B3_X,
        H2B3_Y,
        H2B3_W,
        H2B3_H,
        H2B3_BGC
    );

    tft.drawRect(
        H2B3_X,
        H2B3_Y,
        H2B3_W,
        H2B3_H,
        H2B3_BC
    );

    tft.setTextColor(
        H2B3_TC,
        H2B3_BGC
    );

    tft.drawString(
        "SET",
        H2B3_X + H2B3_W / 2,
        H2B3_Y + H2B3_H / 2
    );

    // Ligne basse
    tft.drawFastHLine(
        0,
        H2_Y + H2_H - 1,
        SCREEN_WIDTH,
        H2_LINE_C
    );

    tft.setTextDatum(TL_DATUM);
}

// H2B1 clic
bool header2MenuPressed(int16_t x, int16_t y)
{
    return (
        x >= H2B1_X &&
        x < H2B1_X + H2B1_W &&
        y >= H2B1_Y &&
        y < H2B1_Y + H2B1_H
    );
}

// H2B3 clic
bool header2SettingsPressed(int16_t x, int16_t y)
{
    return (
        x >= H2B3_X &&
        x < H2B3_X + H2B3_W &&
        y >= H2B3_Y &&
        y < H2B3_Y + H2B3_H
    );
}