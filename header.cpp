#include "header.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "settings.h"

// ============================================================
// OUTIL INTERNE
// Dessine un bloc avec fond + bordure
// ============================================================

static void drawBlock(
  int16_t x,
  int16_t y,
  int16_t w,
  int16_t h,
  uint16_t bgc,
  uint16_t bc
)
{
  tft.fillRect(
    x,
    y,
    w,
    h,
    bgc
  );

  tft.drawRect(
    x,
    y,
    w,
    h,
    bc
  );
}

// ============================================================
// HEADER 1
// ============================================================

void header1Draw()
{
  // ----------------------------------------------------------
  // H1B1 : HEURE
  // ----------------------------------------------------------

  drawBlock(
    H1B1_X,
    H1B1_Y,
    H1B1_W,
    H1B1_H,
    H1B1_BGC,
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

  // ----------------------------------------------------------
  // H1B2 : DATE
  // ----------------------------------------------------------

  drawBlock(
    H1B2_X,
    H1B2_Y,
    H1B2_W,
    H1B2_H,
    H1B2_BGC,
    H1B2_BC
  );

  tft.setTextSize(H1B2_TEXT_SIZE);

  tft.setTextColor(
    H1B2_TC,
    H1B2_BGC
  );

  tft.drawString(
    "2026:08:12",
    H1B2_X + H1B2_W / 2,
    H1B2_Y + H1B2_H / 2
  );

  // ----------------------------------------------------------
  // H1B3 : LOGO
  // ----------------------------------------------------------

  drawBlock(
    H1B3_X,
    H1B3_Y,
    H1B3_W,
    H1B3_H,
    H1B3_BGC,
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

  // ----------------------------------------------------------
  // H1B4 : STATUS
  // ----------------------------------------------------------

  drawBlock(
    H1B4_X,
    H1B4_Y,
    H1B4_W,
    H1B4_H,
    H1B4_BGC,
    H1B4_BC
  );

  // ----------------------------------------------------------
  // H1B4 : CARRES
  // ----------------------------------------------------------

  const int totalSquaresWidth =
    (H1B4_SQUARE_COUNT * H1B4_SQUARE_SIZE) +
    ((H1B4_SQUARE_COUNT - 1) * H1B4_SQUARE_SPACING);

  const int startX =
    H1B4_X +
    (H1B4_W - totalSquaresWidth) / 2;

  const int startY =
    H1B4_Y +
    (H1B4_H - H1B4_SQUARE_SIZE) / 2;

  for (int i = 0; i < H1B4_SQUARE_COUNT; i++)
  {
    const int squareX =
      startX +
      i * (H1B4_SQUARE_SIZE + H1B4_SQUARE_SPACING);

    tft.fillRect(
      squareX,
      startY,
      H1B4_SQUARE_SIZE,
      H1B4_SQUARE_SIZE,
      H1B4_SQUARE_BGC
    );

    tft.drawRect(
      squareX,
      startY,
      H1B4_SQUARE_SIZE,
      H1B4_SQUARE_SIZE,
      H1B4_SQUARE_BC
    );
  }

  tft.setTextDatum(TL_DATUM);
}

// ============================================================
// HEADER 2
// ============================================================

void header2Draw(const char *title)
{
  // ----------------------------------------------------------
  // H2B1 : MENU
  // ----------------------------------------------------------

  drawBlock(
    H2B1_X,
    H2B1_Y,
    H2B1_W,
    H2B1_H,
    H2B1_BGC,
    H2B1_BC
  );

  tft.setTextSize(H2B1_TEXT_SIZE);
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

  // ----------------------------------------------------------
  // H2B2 : TITRE
  // ----------------------------------------------------------

  drawBlock(
    H2B2_X,
    H2B2_Y,
    H2B2_W,
    H2B2_H,
    H2B2_BGC,
    H2B2_BC
  );

  tft.setTextSize(H2B2_TEXT_SIZE);

  tft.setTextColor(
    H2B2_TC,
    H2B2_BGC
  );

  tft.drawString(
    title,
    H2B2_X + H2B2_W / 2,
    H2B2_Y + H2B2_H / 2
  );

  // ----------------------------------------------------------
  // H2B3 : SETTINGS
  // ----------------------------------------------------------

  drawBlock(
    H2B3_X,
    H2B3_Y,
    H2B3_W,
    H2B3_H,
    H2B3_BGC,
    H2B3_BC
  );

  tft.setTextSize(H2B3_TEXT_SIZE);

  tft.setTextColor(
    H2B3_TC,
    H2B3_BGC
  );

  tft.drawString(
    "*",
    H2B3_X + H2B3_W / 2,
    H2B3_Y + H2B3_H / 2
  );

  // ----------------------------------------------------------
  // Ligne basse
  // ----------------------------------------------------------

  tft.drawFastHLine(
    0,
    H2_Y + H2_H - 1,
    SCREEN_WIDTH,
    H2_LINE_C
  );

  tft.setTextDatum(TL_DATUM);
}

// ============================================================
// H2B1 : DETECTION MENU
// ============================================================

bool header2MenuPressed(
  int16_t x,
  int16_t y
)
{
  return (
    x >= H2B1_X &&
    x < H2B1_X + H2B1_W &&
    y >= H2B1_Y &&
    y < H2B1_Y + H2B1_H
  );
}

// ============================================================
// H2B3 : DETECTION SETTINGS
// ============================================================

bool header2SettingsPressed(
  int16_t x,
  int16_t y
)
{
  return (
    x >= H2B3_X &&
    x < H2B3_X + H2B3_W &&
    y >= H2B3_Y &&
    y < H2B3_Y + H2B3_H
  );
}