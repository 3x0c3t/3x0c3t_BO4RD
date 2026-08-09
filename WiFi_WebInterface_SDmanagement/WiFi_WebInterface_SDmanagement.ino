#include <Arduino.h>
#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "config.h"

// ============================================================
// TFT
// ============================================================

Adafruit_ILI9341 tft(
    TFT_CS,
    TFT_DC,
    TFT_RST
);

// ============================================================
// SETUP
// ============================================================

void setup()
{
    // --------------------------------------------------------
    // SERIAL
    // --------------------------------------------------------

    Serial.begin(115200);

    delay(1000);

    Serial.println();
    Serial.println();
    Serial.println("================================");
    Serial.println("3x0c3t TFT TEST");
    Serial.println("================================");

    Serial.println(
        "[TFT] Initialisation"
    );

    // --------------------------------------------------------
    // CS
    // --------------------------------------------------------

    pinMode(
        TFT_CS,
        OUTPUT
    );

    digitalWrite(
        TFT_CS,
        HIGH
    );

    // --------------------------------------------------------
    // SPI
    // --------------------------------------------------------

    SPI.begin();

    delay(100);

    Serial.println(
        "[SPI] OK"
    );

    // --------------------------------------------------------
    // TFT
    // --------------------------------------------------------

    tft.begin();

    delay(500);

    Serial.println(
        "[TFT] begin() OK"
    );

    // --------------------------------------------------------
    // ROTATION
    // --------------------------------------------------------

    tft.setRotation(1);

    delay(100);

    // --------------------------------------------------------
    // TEST ROUGE
    // --------------------------------------------------------

    Serial.println(
        "[TFT] ROUGE"
    );

    tft.fillScreen(
        ILI9341_RED
    );

    delay(2000);

    // --------------------------------------------------------
    // TEST VERT
    // --------------------------------------------------------

    Serial.println(
        "[TFT] VERT"
    );

    tft.fillScreen(
        ILI9341_GREEN
    );

    delay(2000);

    // --------------------------------------------------------
    // TEST BLEU
    // --------------------------------------------------------

    Serial.println(
        "[TFT] BLEU"
    );

    tft.fillScreen(
        ILI9341_BLUE
    );

    delay(2000);

    // --------------------------------------------------------
    // NOIR
    // --------------------------------------------------------

    Serial.println(
        "[TFT] NOIR"
    );

    tft.fillScreen(
        ILI9341_BLACK
    );

    delay(500);

    // --------------------------------------------------------
    // TEXTE
    // --------------------------------------------------------

    tft.setTextColor(
        ILI9341_WHITE
    );

    tft.setTextSize(2);

    tft.setCursor(
        10,
        10
    );

    tft.println(
        "3x0c3t"
    );

    tft.println(
        "TFT TEST"
    );

    tft.setTextSize(1);

    tft.setCursor(
        10,
        60
    );

    tft.print(
        "CS  = GPIO "
    );

    tft.println(
        TFT_CS
    );

    tft.setCursor(
        10,
        80
    );

    tft.print(
        "DC  = GPIO "
    );

    tft.println(
        TFT_DC
    );

    tft.setCursor(
        10,
        100
    );

    tft.print(
        "RST = GPIO "
    );

    tft.println(
        TFT_RST
    );

    tft.setCursor(
        10,
        140
    );

    tft.println(
        "ILI9341 TEST OK"
    );

    Serial.println(
        "[TFT] TEST TERMINE"
    );
}

// ============================================================
// LOOP
// ============================================================

void loop()
{
    static unsigned long timer = 0;

    if (
        millis() - timer > 3000
    )
    {
        timer = millis();

        Serial.println(
            "[LOOP] TFT actif"
        );
    }

    delay(10);
}