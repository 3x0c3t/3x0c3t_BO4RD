#include "menu.h"
#include "display.h"
#include "settings.h"
#include "buttons.h"
#include "header.h"

void menuDraw()
{
  tft.fillScreen(CONTENT_BGC);

  header1Draw();
  header2Draw("MENU");

  const int startY = CONTENT_Y + 10;

  buttonDraw(
    BUTTON_X,
    startY,
    BUTTON_W,
    BUTTON_H,
    "PAGE 1"
  );

  buttonDraw(
    BUTTON_X,
    startY + BUTTON_H + BUTTON_SPACING,
    BUTTON_W,
    BUTTON_H,
    "PAGE 2"
  );

  buttonDraw(
    BUTTON_X,
    startY + (BUTTON_H + BUTTON_SPACING) * 2,
    BUTTON_W,
    BUTTON_H,
    "PAGE 3"
  );
}