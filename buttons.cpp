#include "buttons.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "settings.h"

// BUTTON | carré
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
    H1_SQUARE_BGC
  );

  tft.drawRect(
    x,
    y,
    size,
    size,
    H1_SQUARE_BC
  );
}

// BUTTON | bouton principal
void buttonDraw(
  int16_t x,
  int16_t y,
  int16_t w,
  int16_t h,
  const char *title
)
{
  tft.fillRoundRect(
    x,
    y,
    w,
    h,
    BUTTON_RADIUS,
    BUTTON_BGC
  );

  tft.drawRoundRect(
    x,
    y,
    w,
    h,
    BUTTON_RADIUS,
    BUTTON_BC
  );

  // BUTTON | titre
  tft.setTextSize(1);
  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(
    BUTTON_TC,
    BUTTON_BGC
  );

  tft.drawString(
    title,
    x + w / 2,
    y + h / 2
  );

  tft.setTextDatum(TL_DATUM);
}