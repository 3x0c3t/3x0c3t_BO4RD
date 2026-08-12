#include "header.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "settings.h"


// ============================================================
// HEADER 1
// ============================================================

void header1Draw()
{
  // ==========================================================
  // FOND VERT
  // ==========================================================

  tft.fillRect(
    0,
    HEADER1_Y,
    SCREEN_WIDTH,
    HEADER1_HEIGHT,
    COLOR_HEADER1_BG
  );


  // ==========================================================
  // HEURE + DATE
  // ==========================================================

  tft.setTextSize(1);

  tft.setTextColor(
    COLOR_HEADER1_TEXT,
    COLOR_HEADER1_BG
  );

  tft.setTextDatum(TL_DATUM);


  // ----------------------------------------------------------
  // HEURE
  // ----------------------------------------------------------

  tft.drawString(
    "12:34:56",
    3,
    HEADER1_Y + 6
  );


  // ----------------------------------------------------------
  // DATE
  // ----------------------------------------------------------

  tft.drawString(
    "20260812",
    65,
    HEADER1_Y + 6
  );


  // ==========================================================
  // MARQUE 3X0C3T
  // ==========================================================

  const int brandX = 125;
  const int brandY = HEADER1_Y + 3;
  const int brandW = 65;
  const int brandH = 14;


  // ----------------------------------------------------------
  // FOND NOIR
  // ----------------------------------------------------------

  tft.fillRect(
    brandX,
    brandY,
    brandW,
    brandH,
    COLOR_BRAND_BG
  );


  // ----------------------------------------------------------
  // CONTOUR VERT
  // ----------------------------------------------------------

  tft.drawRect(
    brandX,
    brandY,
    brandW,
    brandH,
    COLOR_BRAND_BORDER
  );


  // ----------------------------------------------------------
  // TEXTE ROUGE
  // ----------------------------------------------------------

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


  // ==========================================================
  // CONTENEUR DES 2 CARRÉS
  // ==========================================================

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


  // ----------------------------------------------------------
  // FOND NOIR
  // ----------------------------------------------------------

  tft.fillRect(
    containerX,
    containerY,
    containerW,
    containerH,
    TFT_BLACK
  );


  // ----------------------------------------------------------
  // CONTOUR VERT 1 PX
  // ----------------------------------------------------------

  tft.drawRect(
    containerX,
    containerY,
    containerW,
    containerH,
    TFT_GREEN
  );


  // ==========================================================
  // CARRÉ 1
  // ==========================================================

  const int squareY =
    containerY + containerPadding;


  const int square1X =
    containerX + containerPadding;


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


  // ==========================================================
  // CARRÉ 2
  // ==========================================================

  const int square2X =
    square1X +
    squareSize +
    squareSpacing;


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


  // ----------------------------------------------------------
  // RESET TEXTE
  // ----------------------------------------------------------

  tft.setTextDatum(TL_DATUM);
}


// ============================================================
// ICÔNE MENU BURGER
// ============================================================

void drawBurgerIcon(
  int16_t centerX,
  int16_t centerY
)
{
  const int width = 20;
  const int lineHeight = 2;
  const int spacing = 5;


  const int x =
    centerX - width / 2;


  const int y1 =
    centerY - spacing;


  const int y2 =
    centerY;


  const int y3 =
    centerY + spacing;


  // ----------------------------------------------------------
  // Ligne 1
  // ----------------------------------------------------------

  tft.fillRect(
    x,
    y1,
    width,
    lineHeight,
    TFT_WHITE
  );


  // ----------------------------------------------------------
  // Ligne 2
  // ----------------------------------------------------------

  tft.fillRect(
    x,
    y2,
    width,
    lineHeight,
    TFT_WHITE
  );


  // ----------------------------------------------------------
  // Ligne 3
  // ----------------------------------------------------------

  tft.fillRect(
    x,
    y3,
    width,
    lineHeight,
    TFT_WHITE
  );
}


// ============================================================
// HEADER 2
// ============================================================

void header2Draw(
  const char *title
)
{
  // ==========================================================
  // FOND NOIR
  // ==========================================================

  tft.fillRect(
    0,
    HEADER2_Y,
    SCREEN_WIDTH,
    HEADER2_HEIGHT,
    COLOR_HEADER2_BG
  );


  // ==========================================================
  // CENTRE VERTICAL
  // ==========================================================

  const int headerCenterY =
    HEADER2_Y +
    HEADER2_HEIGHT / 2;


  // ==========================================================
  // MENU BURGER
  // ==========================================================

  const int menuCenterX =
    HEADER2_MENU_X +
    HEADER2_MENU_WIDTH / 2;


  drawBurgerIcon(
    menuCenterX,
    headerCenterY
  );


  // ==========================================================
  // TITRE
  // ==========================================================

  tft.setTextSize(1);

  tft.setTextColor(
    COLOR_HEADER2_TEXT,
    COLOR_HEADER2_BG
  );

  tft.setTextDatum(MC_DATUM);


  tft.drawString(
    title,
    HEADER2_TITLE_X +
      HEADER2_TITLE_WIDTH / 2,
    headerCenterY
  );


  // ==========================================================
  // SETTINGS [*]
  // ==========================================================

  const int settingsCenterX =
    HEADER2_SETTINGS_X +
    HEADER2_SETTINGS_WIDTH / 2;


  tft.setTextDatum(MC_DATUM);


  tft.drawString(
    "[*]",
    settingsCenterX,
    headerCenterY
  );


  // ==========================================================
  // LIGNE BAS HEADER 2
  // ==========================================================

  tft.drawFastHLine(
    0,
    HEADER2_Y +
      HEADER2_HEIGHT -
      1,
    SCREEN_WIDTH,
    COLOR_LINE
  );


  // ----------------------------------------------------------
  // RESET
  // ----------------------------------------------------------

  tft.setTextDatum(TL_DATUM);
}


// ============================================================
// TOUCH - MENU
// ============================================================

bool header2MenuPressed(
  int16_t x,
  int16_t y
)
{
  return (
    x >= HEADER2_MENU_X &&
    x < HEADER2_MENU_X + HEADER2_MENU_WIDTH &&
    y >= HEADER2_Y &&
    y < HEADER2_Y + HEADER2_HEIGHT
  );
}


// ============================================================
// TOUCH - SETTINGS
// ============================================================

bool header2SettingsPressed(
  int16_t x,
  int16_t y
)
{
  return (
    x >= HEADER2_SETTINGS_X &&
    x < HEADER2_SETTINGS_X + HEADER2_SETTINGS_WIDTH &&
    y >= HEADER2_Y &&
    y < HEADER2_Y + HEADER2_HEIGHT
  );
}


// ============================================================
// TOUCH - TITRE
// ============================================================

bool header2TitlePressed(
  int16_t x,
  int16_t y
)
{
  return (
    x >= HEADER2_TITLE_X &&
    x < HEADER2_TITLE_X + HEADER2_TITLE_WIDTH &&
    y >= HEADER2_Y &&
    y < HEADER2_Y + HEADER2_HEIGHT
  );
}