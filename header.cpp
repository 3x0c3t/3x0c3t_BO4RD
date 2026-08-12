#include "header.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "settings.h"

// HEADER 1 | affichage
void header1Draw()
{
  tft.fillRect(
    0,
    HEADER1_Y,
    SCREEN_WIDTH,
    HEADER1_HEIGHT,
    COLOR_HEADER1_BG
  );

  tft.setTextSize(1);
  tft.setTextColor(
    COLOR_HEADER1_TEXT,
    COLOR_HEADER1_BG
  );
  tft.setTextDatum(TL_DATUM);

  tft.drawString(
    "12:34:56",
    3,
    6
  );

  tft.drawString(
    "20260812",
    65,
    6
  );

  const int brandX = 125;
  const int brandY = 3;
  const int brandW = 65;
  const int brandH = 14;

  tft.fillRect(
    brandX,
    brandY,
    brandW,
    brandH,
    COLOR_BRAND_BG
  );

  tft.drawRect(
    brandX,
    brandY,
    brandW,
    brandH,
    COLOR_BRAND_BORDER
  );

  tft.setTextColor(
    COLOR_BRAND_TEXT,
    COLOR_BRAND_BG
  );

  tft.setTextDatum(MC_DATUM);

  tft.drawString(
    "- 3X0C3T -",
    brandX + brandW / 2,
    brandY + brandH / 2
  );

  const int squareSize = 10;
  const int squareSpacing = 4;
  const int containerPadding = 3;

  const int containerW =
    containerPadding * 2 +
    squareSize * 2 +
    squareSpacing;

  const int containerH =
    squareSize +
    containerPadding * 2;

  const int containerX =
    SCREEN_WIDTH -
    containerW -
    3;

  const int containerY =
    HEADER1_Y +
    (HEADER1_HEIGHT - containerH) / 2;

  tft.fillRect(
    containerX,
    containerY,
    containerW,
    containerH,
    COLOR_SQUARE_BG
  );

  tft.drawRect(
    containerX,
    containerY,
    containerW,
    containerH,
    COLOR_BRAND_BORDER
  );

  const int squareY =
    containerY +
    containerPadding;

  const int square1X =
    containerX +
    containerPadding;

  const int square2X =
    square1X +
    squareSize +
    squareSpacing;

  tft.fillRect(
    square1X,
    squareY,
    squareSize,
    squareSize,
    COLOR_SQUARE_BG
  );

  tft.drawRect(
    square1X,
    squareY,
    squareSize,
    squareSize,
    COLOR_SQUARE_BORDER
  );

  tft.fillRect(
    square2X,
    squareY,
    squareSize,
    squareSize,
    COLOR_SQUARE_BG
  );

  tft.drawRect(
    square2X,
    squareY,
    squareSize,
    squareSize,
    COLOR_SQUARE_BORDER
  );

  tft.setTextDatum(TL_DATUM);
}

// HEADER 2 | affichage
void header2Draw(const char *title)
{
  const int y = HEADER2_Y;
  const int h = HEADER2_HEIGHT;

  // HEADER 2 | zone MENU
  tft.fillRect(
    HEADER2_MENU_X,
    y,
    HEADER2_MENU_WIDTH,
    h,
    COLOR_HEADER2_MENU_BG
  );

  tft.drawRect(
    HEADER2_MENU_X,
    y,
    HEADER2_MENU_WIDTH,
    h,
    COLOR_HEADER2_MENU_BORDER
  );

  // HEADER 2 | zone TITRE
  tft.fillRect(
    HEADER2_TITLE_X,
    y,
    HEADER2_TITLE_WIDTH,
    h,
    COLOR_HEADER2_TITLE_BG
  );

  tft.drawRect(
    HEADER2_TITLE_X,
    y,
    HEADER2_TITLE_WIDTH,
    h,
    COLOR_HEADER2_TITLE_BORDER
  );

  // HEADER 2 | zone SETTINGS
  tft.fillRect(
    HEADER2_SETTINGS_X,
    y,
    HEADER2_SETTINGS_WIDTH,
    h,
    COLOR_HEADER2_SETTINGS_BG
  );

  tft.drawRect(
    HEADER2_SETTINGS_X,
    y,
    HEADER2_SETTINGS_WIDTH,
    h,
    COLOR_HEADER2_SETTINGS_BORDER
  );

  // HEADER 2 | configuration texte
  tft.setTextSize(1);
  tft.setTextDatum(MC_DATUM);

  // HEADER 2 | symbole MENU
  tft.setTextColor(
    COLOR_HEADER2_TEXT,
    COLOR_HEADER2_MENU_BG
  );

  tft.drawString(
    "☰",
    HEADER2_MENU_X + HEADER2_MENU_WIDTH / 2,
    y + h / 2
  );

  // HEADER 2 | titre
  tft.setTextColor(
    COLOR_HEADER2_TEXT,
    COLOR_HEADER2_TITLE_BG
  );

  tft.drawString(
    title,
    HEADER2_TITLE_X + HEADER2_TITLE_WIDTH / 2,
    y + h / 2
  );

  // HEADER 2 | symbole SETTINGS
  tft.setTextColor(
    COLOR_HEADER2_TEXT,
    COLOR_HEADER2_SETTINGS_BG
  );

  tft.drawString(
    "[*]",
    HEADER2_SETTINGS_X + HEADER2_SETTINGS_WIDTH / 2,
    y + h / 2
  );

  tft.setTextDatum(TL_DATUM);
}

// HEADER 2 | test bouton MENU
bool header2MenuPressed(int16_t x, int16_t y)
{
  return (
    x >= HEADER2_MENU_X &&
    x < HEADER2_MENU_X + HEADER2_MENU_WIDTH &&
    y >= HEADER2_Y &&
    y < HEADER2_Y + HEADER2_HEIGHT
  );
}

// HEADER 2 | test bouton SETTINGS
bool header2SettingsPressed(int16_t x, int16_t y)
{
  return (
    x >= HEADER2_SETTINGS_X &&
    x < HEADER2_SETTINGS_X + HEADER2_SETTINGS_WIDTH &&
    y >= HEADER2_Y &&
    y < HEADER2_Y + HEADER2_HEIGHT
  );
}