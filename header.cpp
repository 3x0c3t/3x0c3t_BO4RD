#include "header.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "settings.h"

// H1 | affichage
void header1Draw()
{
  tft.fillRect(
    0,
    H1_Y,
    SCREEN_WIDTH,
    H1_H,
    H1_BGC
  );

  // H1 | heure
  tft.fillRect(
    H1_TIME_X,
    0,
    57,
    H1_H,
    H1_TIME_BGC
  );

  tft.drawRect(
    H1_TIME_X,
    0,
    57,
    H1_H,
    H1_TIME_BC
  );

  tft.setTextSize(1);
  tft.setTextDatum(TL_DATUM);
  tft.setTextColor(
    H1_TIME_TC,
    H1_TIME_BGC
  );

  tft.drawString(
    "12:34:56",
    H1_TIME_X,
    H1_TIME_Y
  );

  // H1 | date
  tft.fillRect(
    H1_DATE_X,
    0,
    55,
    H1_H,
    H1_DATE_BGC
  );

  tft.drawRect(
    H1_DATE_X,
    0,
    55,
    H1_H,
    H1_DATE_BC
  );

  tft.setTextColor(
    H1_DATE_TC,
    H1_DATE_BGC
  );

  tft.drawString(
    "2026:08:12",
    H1_DATE_X,
    H1_DATE_Y
  );

  // H1 | logo
  tft.fillRect(
    H1_LOGO_X,
    H1_LOGO_Y,
    H1_LOGO_W,
    H1_LOGO_H,
    H1_LOGO_BGC
  );

  tft.drawRect(
    H1_LOGO_X,
    H1_LOGO_Y,
    H1_LOGO_W,
    H1_LOGO_H,
    H1_LOGO_BC
  );

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(
    H1_LOGO_TC,
    H1_LOGO_BGC
  );

  tft.drawString(
    "- 3X0C3T -",
    H1_LOGO_X + H1_LOGO_W / 2,
    H1_LOGO_Y + H1_LOGO_H / 2
  );

  // H1 | conteneur status
  const int containerW =
    H1_STATUS_PADDING * 2 +
    H1_STATUS_SQUARE_SIZE * 2 +
    H1_STATUS_SQUARE_SPACING;

  const int containerH =
    H1_STATUS_PADDING * 2 +
    H1_STATUS_SQUARE_SIZE;

  const int containerX =
    SCREEN_WIDTH -
    containerW -
    H1_STATUS_MARGIN;

  const int containerY =
    H1_Y +
    (H1_H - containerH) / 2;

  tft.fillRect(
    containerX,
    containerY,
    containerW,
    containerH,
    H1_STATUS_BGC
  );

  tft.drawRect(
    containerX,
    containerY,
    containerW,
    containerH,
    H1_STATUS_BC
  );

  // H1 | carré 1
  const int squareY =
    containerY + H1_STATUS_PADDING;

  const int square1X =
    containerX + H1_STATUS_PADDING;

  tft.fillRect(
    square1X,
    squareY,
    H1_STATUS_SQUARE_SIZE,
    H1_STATUS_SQUARE_SIZE,
    H1_STATUS_SQUARE_BGC
  );

  tft.drawRect(
    square1X,
    squareY,
    H1_STATUS_SQUARE_SIZE,
    H1_STATUS_SQUARE_SIZE,
    H1_STATUS_SQUARE_BC
  );

  // H1 | carré 2
  const int square2X =
    square1X +
    H1_STATUS_SQUARE_SIZE +
    H1_STATUS_SQUARE_SPACING;

  tft.fillRect(
    square2X,
    squareY,
    H1_STATUS_SQUARE_SIZE,
    H1_STATUS_SQUARE_SIZE,
    H1_STATUS_SQUARE_BGC
  );

  tft.drawRect(
    square2X,
    squareY,
    H1_STATUS_SQUARE_SIZE,
    H1_STATUS_SQUARE_SIZE,
    H1_STATUS_SQUARE_BC
  );

  tft.setTextDatum(TL_DATUM);
}

// H2 | affichage
void header2Draw(const char *title)
{
  // H2 | fond
  tft.fillRect(
    0,
    H2_Y,
    SCREEN_WIDTH,
    H2_H,
    TFT_BLACK
  );

  // H2B1 | bouton menu
  tft.fillRect(
    H2B1_X,
    H2_Y,
    H2B1_W,
    H2_H,
    H2B1_BGC
  );

  tft.drawRect(
    H2B1_X,
    H2_Y,
    H2B1_W,
    H2_H,
    H2B1_BC
  );

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(
    H2B1_TC,
    H2B1_BGC
  );

  tft.drawString(
    "☰",
    H2B1_X + H2B1_W / 2,
    H2_Y + H2_H / 2
  );

  // H2B2 | titre
  tft.fillRect(
    H2B2_X,
    H2_Y,
    H2B2_W,
    H2_H,
    H2B2_BGC
  );

  tft.drawRect(
    H2B2_X,
    H2_Y,
    H2B2_W,
    H2_H,
    H2B2_BC
  );

  tft.setTextColor(
    H2B2_TC,
    H2B2_BGC
  );

  tft.drawString(
    title,
    H2B2_X + H2B2_W / 2,
    H2_Y + H2_H / 2
  );

  // H2B3 | settings
  tft.fillRect(
    H2B3_X,
    H2_Y,
    H2B3_W,
    H2_H,
    H2B3_BGC
  );

  tft.drawRect(
    H2B3_X,
    H2_Y,
    H2B3_W,
    H2_H,
    H2B3_BC
  );

  tft.setTextColor(
    H2B3_TC,
    H2B3_BGC
  );

  tft.drawString(
    "[*]",
    H2B3_X + H2B3_W / 2,
    H2_Y + H2_H / 2
  );

  // H2 | ligne basse
  tft.drawFastHLine(
    0,
    H2_Y + H2_H - 1,
    SCREEN_WIDTH,
    H2_LINE_C
  );

  tft.setTextDatum(TL_DATUM);
}

// H2B1 | détection clic
bool header2MenuPressed(int16_t x, int16_t y)
{
  return (
    x >= H2B1_X &&
    x < H2B1_X + H2B1_W &&
    y >= H2_Y &&
    y < H2_Y + H2_H
  );
}

// H2B3 | détection clic
bool header2SettingsPressed(int16_t x, int16_t y)
{
  return (
    x >= H2B3_X &&
    x < H2B3_X + H2B3_W &&
    y >= H2_Y &&
    y < H2_Y + H2_H
  );
}