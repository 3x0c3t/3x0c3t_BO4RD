#include "header.h"
#include "display.h"
#include "settings.h"

void header1Draw()
{
  tft.fillRect(
    0,
    H1_Y,
    SCREEN_WIDTH,
    H1_H,
    H1_BGC
  );

  tft.setTextSize(1);
  tft.setTextDatum(TL_DATUM);

  tft.setTextColor(
    H1_TC,
    H1_BGC
  );

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

  const int logoX = 125;
  const int logoY = 3;
  const int logoW = 65;
  const int logoH = 14;

  tft.fillRect(
    logoX,
    logoY,
    logoW,
    logoH,
    H1_LOGO_BGC
  );

  tft.drawRect(
    logoX,
    logoY,
    logoW,
    logoH,
    H1_LOGO_BC
  );

  tft.setTextDatum(MC_DATUM);

  tft.setTextColor(
    H1_LOGO_TC,
    H1_LOGO_BGC
  );

  tft.drawString(
    "- 3X0C3T -",
    logoX + logoW / 2,
    logoY + logoH / 2
  );

  const int squareSize = 10;
  const int squareSpacing = 4;
  const int padding = 3;

  const int containerW =
    padding * 2
    + squareSize * 2
    + squareSpacing;

  const int containerH =
    squareSize
    + padding * 2;

  const int containerX =
    SCREEN_WIDTH
    - containerW
    - 3;

  const int containerY =
    H1_Y
    + (H1_H - containerH) / 2;

  tft.fillRect(
    containerX,
    containerY,
    containerW,
    containerH,
    H1_SQUARE_BGC
  );

  tft.drawRect(
    containerX,
    containerY,
    containerW,
    containerH,
    H1_SQUARE_BC
  );

  const int squareY =
    containerY + padding;

  const int square1X =
    containerX + padding;

  const int square2X =
    square1X
    + squareSize
    + squareSpacing;

  squareDrawHeader(
    square1X,
    squareY,
    squareSize
  );

  squareDrawHeader(
    square2X,
    squareY,
    squareSize
  );

  tft.setTextDatum(TL_DATUM);
}

void squareDrawHeader(
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

void header2Draw(
  const char *title
)
{
  const int y = H2_Y;
  const int h = H2_H;

  tft.fillRect(
    H2_MENU_X,
    y,
    H2_MENU_W,
    h,
    H2_MENU_BGC
  );

  tft.drawRect(
    H2_MENU_X,
    y,
    H2_MENU_W,
    h,
    H2_MENU_BC
  );

  tft.fillRect(
    H2_TITLE_X,
    y,
    H2_TITLE_W,
    h,
    H2_TITLE_BGC
  );

  tft.drawRect(
    H2_TITLE_X,
    y,
    H2_TITLE_W,
    h,
    H2_TITLE_BC
  );

  tft.fillRect(
    H2_SETTINGS_X,
    y,
    H2_SETTINGS_W,
    h,
    H2_SETTINGS_BGC
  );

  tft.drawRect(
    H2_SETTINGS_X,
    y,
    H2_SETTINGS_W,
    h,
    H2_SETTINGS_BC
  );

  tft.setTextSize(1);
  tft.setTextColor(
    H2_TC,
    H2_MENU_BGC
  );

  tft.setTextDatum(MC_DATUM);

  tft.drawString(
    "☰",
    H2_MENU_X + H2_MENU_W / 2,
    y + h / 2
  );

  tft.setTextColor(
    H2_TC,
    H2_TITLE_BGC
  );

  tft.drawString(
    title,
    H2_TITLE_X + H2_TITLE_W / 2,
    y + h / 2
  );

  tft.setTextColor(
    H2_TC,
    H2_SETTINGS_BGC
  );

  tft.drawString(
    "[*]",
    H2_SETTINGS_X + H2_SETTINGS_W / 2,
    y + h / 2
  );

  tft.drawFastHLine(
    0,
    y + h - 1,
    SCREEN_WIDTH,
    H2_LINE_C
  );

  tft.setTextDatum(TL_DATUM);
}

bool header2MenuPressed(
  int16_t x,
  int16_t y
)
{
  return (
    x >= H2_MENU_X &&
    x < H2_MENU_X + H2_MENU_W &&
    y >= H2_Y &&
    y < H2_Y + H2_H
  );
}

bool header2SettingsPressed(
  int16_t x,
  int16_t y
)
{
  return (
    x >= H2_SETTINGS_X &&
    x < H2_SETTINGS_X + H2_SETTINGS_W &&
    y >= H2_Y &&
    y < H2_Y + H2_H
  );
}