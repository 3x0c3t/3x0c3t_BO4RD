cat > display.cpp <<'EOF'
#include "display.h"
#include "config.h"


TFT_eSPI tft = TFT_eSPI();


// ============================================================
// INITIALISATION TFT
// ============================================================

void displayInit()
{
    Serial.println();
    Serial.println("[TFT] Initialisation...");

    tft.init();

    Serial.println("[TFT] tft.init() OK");

    tft.setRotation(
        TFT_ROTATION
    );

    Serial.print("[TFT] Rotation = ");
    Serial.println(TFT_ROTATION);

    clearScreen();

    Serial.println("[TFT] Ecran efface");
    Serial.println("[TFT] TFT : OK");
}


// ============================================================
// EFFACER ECRAN
// ============================================================

void clearScreen()
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );
}


// ============================================================
// TEXTE CENTRE
// ============================================================

void centerText(
    String text,
    int y,
    uint8_t font,
    uint16_t color
)
{
    tft.setTextDatum(
        MC_DATUM
    );

    tft.setTextColor(
        color,
        COLOR_BACKGROUND
    );

    tft.drawString(
        text,
        SCREEN_WIDTH / 2,
        y,
        font
    );
}


// ============================================================
// TITRE
// ============================================================

void drawTitle(
    String title
)
{
    tft.setTextDatum(
        MC_DATUM
    );

    tft.setTextColor(
        COLOR_PRIMARY,
        COLOR_BACKGROUND
    );

    tft.drawString(
        title,
        SCREEN_WIDTH / 2,
        42,
        2
    );

    tft.drawFastHLine(
        0,
        58,
        SCREEN_WIDTH,
        COLOR_LINE
    );
}


// ============================================================
// BARRE DE PROGRESSION
// ============================================================

void drawProgress(
    int percent
)
{
    percent = constrain(
        percent,
        0,
        100
    );

    tft.fillRect(
        0,
        0,
        SCREEN_WIDTH,
        3,
        TFT_DARKGREY
    );

    int width =
        (
            SCREEN_WIDTH * percent
        ) / 100;

    tft.fillRect(
        0,
        0,
        width,
        3,
        COLOR_PRIMARY
    );
}
EOF