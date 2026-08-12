#include "buttons.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "settings.h"


// ============================================================
// CARRÉ
// ============================================================

void squareDraw(
  int16_t x,
  int16_t y,
  int16_t size
)
{
  tft.fillRect(
    x,
    y,
    size,
    size,
    COLOR_SQUARE_BG
  );

  tft.drawRect(
    x,
    y,
    size,
    size,
    COLOR_SQUARE_BORDER
  );
}


// ============================================================
// BOUTON
// ============================================================

void buttonDraw(
  int16_t x,
  int16_t y,
  int16_t w,
  int16_t h,
  const char *title
)
{
  // ----------------------------------------------------------
  // Rectangle arrondi
  // ----------------------------------------------------------

  tft.fillRoundRect(
    x,
    y,
    w,
    h,
    BUTTON_RADIUS,
    COLOR_BUTTON_BG
  );


  // ----------------------------------------------------------
  // Contour
  // ----------------------------------------------------------

  tft.drawRoundRect(
    x,
    y,
    w,
    h,
    BUTTON_RADIUS,
    COLOR_BUTTON_BORDER
  );


  // ----------------------------------------------------------
  // Carré gauche
  // ----------------------------------------------------------

  int squareX =
    x + 8;

  int squareY =
    y + (
      h - BUTTON_LEFT_SQUARE_SIZE
    ) / 2;


  squareDraw(
    squareX,
    squareY,
    BUTTON_LEFT_SQUARE_SIZE
  );


  // ----------------------------------------------------------
  // TITRE
  // ----------------------------------------------------------

  tft.setTextColor(
    COLOR_TITLE,
    COLOR_BUTTON_BG
  );

  tft.setTextSize(1);

  tft.setTextDatum(
    ML_DATUM
  );

  tft.drawString(
    title,
    squareX
      + BUTTON_LEFT_SQUARE_SIZE
      + 10,
    y + h / 2
  );


  // ----------------------------------------------------------
  // Carrés de droite
  // ----------------------------------------------------------

  int rightX =
    x
    + w
    - BUTTON_RIGHT_MARGIN
    - BUTTON_RIGHT_SQUARE_SIZE;


  int rightY =
    y
    + (
      h
      - (
        BUTTON_RIGHT_SQUARE_SIZE * 2
        + BUTTON_RIGHT_SPACING
      )
    ) / 2;


  // ----------------------------------------------------------
  // Carré supérieur
  // ----------------------------------------------------------

  squareDraw(
    rightX,
    rightY,
    BUTTON_RIGHT_SQUARE_SIZE
  );


  // ----------------------------------------------------------
  // Carré inférieur
  // ----------------------------------------------------------

  squareDraw(
    rightX,
    rightY
      + BUTTON_RIGHT_SQUARE_SIZE
      + BUTTON_RIGHT_SPACING,
    BUTTON_RIGHT_SQUARE_SIZE
  );


  tft.setTextDatum(
    TL_DATUM
  );
}