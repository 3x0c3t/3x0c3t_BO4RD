#include "buttons.h"
#include "display.h"
#include "settings.h"

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

  const int leftSquareX =
    x + 8;

  const int leftSquareY =
    y + (h - BUTTON_LEFT_SQUARE_SIZE) / 2;

  squareDraw(
    leftSquareX,
    leftSquareY,
    BUTTON_LEFT_SQUARE_SIZE
  );

  tft.setTextDatum(
    ML_DATUM
  );

  tft.setTextColor(
    BUTTON_TITLE_C,
    BUTTON_BGC
  );

  tft.drawString(
    title,
    leftSquareX + BUTTON_LEFT_SQUARE_SIZE + 10,
    y + h / 2
  );

  const int rightSquareY =
    y + (h - BUTTON_RIGHT_SQUARE_SIZE) / 2;

  const int rightSquare2X =
    x + w
    - BUTTON_RIGHT_MARGIN
    - BUTTON_RIGHT_SQUARE_SIZE;

  const int rightSquare1X =
    rightSquare2X
    - BUTTON_RIGHT_SPACING
    - BUTTON_RIGHT_SQUARE_SIZE;

  squareDraw(
    rightSquare1X,
    rightSquareY,
    BUTTON_RIGHT_SQUARE_SIZE
  );

  squareDraw(
    rightSquare2X,
    rightSquareY,
    BUTTON_RIGHT_SQUARE_SIZE
  );

  tft.setTextDatum(
    TL_DATUM
  );
}