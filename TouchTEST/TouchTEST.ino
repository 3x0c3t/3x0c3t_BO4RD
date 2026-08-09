#include <Arduino.h>

#include "config.h"
#include "display.h"
#include "touch.h"
#include "ui.h"
#include "screens.h"

// =====================================================
// VARIABLES
// =====================================================

static unsigned long lastTouchTime = 0;

#define TOUCH_DEBOUNCE 250

// =====================================================
// SETUP
// =====================================================

void setup()
{
    Serial.begin(
        115200
    );

    delay(1000);

    Serial.println();
    Serial.println(
        "================================"
    );

    Serial.println(
        " 3x0c3t BO4RD"
    );

    Serial.println(
        " TFT + XPT2046"
    );

    Serial.println(
        "================================"
    );

    // =================================================
    // DISPLAY
    // =================================================

    displayInit();

    // =================================================
    // TOUCH
    // =================================================

    touchInit();

    // =================================================
    // UI
    // =================================================

    uiInit();

    // =================================================
    // SCREENS
    // =================================================

    screensInit();

    // =================================================
    // DEMARRAGE
    // =================================================

    Serial.println();
    Serial.println(
        "Demarrage des ecrans..."
    );

    // -------------------------------------------------
    // 1. SPLASH
    // -------------------------------------------------

    screensShow(
        SCREEN_SPLASH
    );

    delay(
        SPLASH_DELAY
    );

    // -------------------------------------------------
    // 2. WIFI
    // -------------------------------------------------

    screensShow(
        SCREEN_WIFI
    );

    delay(3000);

    // -------------------------------------------------
    // 3. INTERFACE PRINCIPALE
    // -------------------------------------------------

    screensShow(
        SCREEN_HOME
    );

    Serial.println();
    Serial.println(
        "Interface principale active."
    );
}

// =====================================================
// LOOP
// =====================================================

void loop()
{
    // =================================================
    // TOUCH
    // =================================================

    int16_t screenX;
    int16_t screenY;

    uint16_t pressure;

    if (
        touchRead(
            screenX,
            screenY,
            pressure
        )
    )
    {
        // -------------------------------------------------
        // Anti-rebond
        // -------------------------------------------------

        if (
            millis() -
            lastTouchTime
            >= TOUCH_DEBOUNCE
        )
        {
            lastTouchTime =
                millis();

            Serial.println(
                "--------------------------------"
            );

            Serial.print(
                "Touch SCREEN X="
            );

            Serial.print(
                screenX
            );

            Serial.print(
                " Y="
            );

            Serial.println(
                screenY
            );

            // -------------------------------------------------
            // Envoyer à l'interface
            // -------------------------------------------------

            uiHandleTouch(
                screenX,
                screenY
            );
        }
    }

    delay(10);
}