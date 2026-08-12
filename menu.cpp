#include "menu.h"

#include "display.h"
#include "settings.h"
#include "buttons.h"
#include "header.h"

// ============================================================
// MENU
// ============================================================

void menuDraw()
{
  // ----------------------------------------------------------
  // Fond
  // ----------------------------------------------------------

  tft.fillScreen(
    CONTENT_BGC
  );

  // ----------------------------------------------------------
  // Headers
  // ----------------------------------------------------------

  header1Draw();

  header2Draw(
    "MENU"
  );

  // ----------------------------------------------------------
  // Boutons
  // ----------------------------------------------------------

  const int startY =
    CONTENT_Y + 10;

  // PAGE 1

  buttonDraw(
    BUTTON_X,
    startY,
    BUTTON_W,
    BUTTON_H,
    "PAGE 1"
  );

  // PAGE 2

  buttonDraw(
    BUTTON_X,
    startY +
      BUTTON_H +
      BUTTON_SPACING,
    BUTTON_W,
    BUTTON_H,
    "PAGE 2"
  );

  // PAGE 3

  buttonDraw(
    BUTTON_X,
    startY +
      (BUTTON_H + BUTTON_SPACING) * 2,
    BUTTON_W,
    BUTTON_H,
    "PAGE 3"
  );
}