#include "header.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "settings.h"


// ============================================================
// HEADER 1
// ============================================================

void header1Draw()
{
  // ----------------------------------------------------------
  // Fond vert
  // ----------------------------------------------------------

  tft.fillRect(
    0,
    HEADER1_Y,
    SCREEN_WIDTH,
    HEADER1_HEIGHT,
    COLOR_HEADER1_BG
  );


  // ----------------------------------------------------------
  // Texte
  // ----------------------------------------------------------

  tft.setTextSize(1);

  tft.setTextColor(
    COLOR_HEADER1_TEXT,
    COLOR_HEADER1_BG
  );

  tft.setTextDatum(
    TL_DATUM
  );


  // ----------------------------------------------------------
  // Heure
  // ----------------------------------------------------------

  tft.drawString(
    "12:34:56",
    3,
    6
  );


  // ----------------------------------------------------------
  // Date
  // ----------------------------------------------------------

  tft.drawString(
    "20260812",
    65,
    6
  );


  // ----------------------------------------------------------
  // Carrés
  // ----------------------------------------------------------

  const int size = 12;

  const int y = 4;

  const int square2X =
    SCREEN_WIDTH - 5 - size;

  const int square1X =
    square2X - 5 - size;


  // ----------------------------------------------------------
  // Carré 1
  // ----------------------------------------------------------

  tft.fillRect(
    square1X,
    y,
    size,
    size,
    COLOR_SQUARE_BG
  );

  tft.drawRect(
    square1X,
    y,
    size,
    size,
    COLOR_SQUARE_BORDER
  );


  // ----------------------------------------------------------
  // Carré 2
  // ----------------------------------------------------------

  tft.fillRect(
    square2X,
    y,
    size,
    size,
    COLOR_SQUARE_BG
  );

  tft.drawRect(
    square2X,
    y,
    size,
    size,
    COLOR_SQUARE_BORDER
  );
}


// ============================================================
// HEADER 2
// ============================================================

void header2Draw(
  const char *title
)
{
  // ----------------------------------------------------------
  // Fond
  // ----------------------------------------------------------

  tft.fillRect(
    0,
    HEADER2_Y,
    SCREEN_WIDTH,
    HEADER2_HEIGHT,
    COLOR_HEADER2_BG
  );


  // ----------------------------------------------------------
  // Texte
  // ----------------------------------------------------------

  tft.setTextSize(1);

  tft.setTextColor(
    COLOR_HEADER2_TEXT,
    COLOR_HEADER2_BG
  );


  // ----------------------------------------------------------
  // MENU
  // ----------------------------------------------------------

  tft.setTextDatum(
    TL_DATUM
  );

  tft.drawString(
    "[MENU]",
    3,
    HEADER2_Y + 6
  );


  // ----------------------------------------------------------
  // TITRE
  // ----------------------------------------------------------

  tft.setTextDatum(
    MC_DATUM
  );

  tft.drawString(
    title,
    SCREEN_WIDTH / 2,
    HEADER2_Y + 10
  );


  // ----------------------------------------------------------
  // SETTINGS
  // ----------------------------------------------------------

  tft.setTextDatum(
    TR_DATUM
  );

  tft.drawString(
    "[SETTINGS]",
    SCREEN_WIDTH - 3,
    HEADER2_Y + 6
  );


  // ----------------------------------------------------------
  // Ligne
  // ----------------------------------------------------------

  tft.drawFastHLine(
    0,
    HEADER2_Y + HEADER2_HEIGHT - 1,
    SCREEN_WIDTH,
    COLOR_LINE
  );


  tft.setTextDatum(
    TL_DATUM
  );
}