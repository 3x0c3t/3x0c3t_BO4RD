#include "display.h"
#include "settings.h"

// ============================================================
// INSTANCE TFT
// ============================================================

TFT_eSPI tft = TFT_eSPI();


// ============================================================
// INITIALISATION
// ============================================================

void displayInit()
{
  Serial.println("[TFT] TFT_eSPI");
  Serial.println("[TFT] ILI9341");
  Serial.println("[TFT] Initialisation...");

  tft.init();

  tft.setRotation(
    TFT_ROTATION
  );

  tft.fillScreen(
    COLOR_BACKGROUND
  );

  Serial.println("[TFT] OK");

  Serial.print("[TFT] Width  = ");
  Serial.println(tft.width());

  Serial.print("[TFT] Height = ");
  Serial.println(tft.height());
}