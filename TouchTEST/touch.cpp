#include "touch.h"
#include "config.h"

#include <SPI.h>

// =====================================================
// Objet XPT2046
// =====================================================

XPT2046_Touchscreen ts(
    TOUCH_CS,
    TOUCH_IRQ
);

// =====================================================
// INITIALISATION
// =====================================================

void touchInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println(" INITIALISATION XPT2046");
    Serial.println("================================");

    pinMode(TOUCH_CS, OUTPUT);

    digitalWrite(
        TOUCH_CS,
        HIGH
    );

    SPI.begin();

    if (ts.begin())
    {
        Serial.println(
            "XPT2046 : OK"
        );

        ts.setRotation(
            TFT_ROTATION
        );
    }
    else
    {
        Serial.println(
            "XPT2046 : ERREUR"
        );
    }

    Serial.println();
}

// =====================================================
// LECTURE + CONVERSION
// =====================================================

bool touchRead(
    int16_t &screenX,
    int16_t &screenY,
    uint16_t &pressure
)
{
    if (!ts.touched())
    {
        return false;
    }

    TS_Point p = ts.getPoint();

    pressure = p.z;

    // -------------------------------------------------
    // Conversion X
    // -------------------------------------------------

    screenX = map(
        p.x,
        TOUCH_RAW_X_MIN,
        TOUCH_RAW_X_MAX,
        0,
        SCREEN_WIDTH - 1
    );

    // -------------------------------------------------
    // Conversion Y
    // -------------------------------------------------

    screenY = map(
        p.y,
        TOUCH_RAW_Y_MIN,
        TOUCH_RAW_Y_MAX,
        0,
        SCREEN_HEIGHT - 1
    );

    // -------------------------------------------------
    // Sécurité
    // -------------------------------------------------

    screenX = constrain(
        screenX,
        0,
        SCREEN_WIDTH - 1
    );

    screenY = constrain(
        screenY,
        0,
        SCREEN_HEIGHT - 1
    );

    // -------------------------------------------------
    // Debug
    // -------------------------------------------------

    touchDebug(
        screenX,
        screenY,
        pressure
    );

    return true;
}

// =====================================================
// DEBUG
// =====================================================

void touchDebug(
    int16_t screenX,
    int16_t screenY,
    uint16_t pressure
)
{
    Serial.print(
        "Touch SCREEN X="
    );

    Serial.print(
        screenX
    );

    Serial.print(
        " Y="
    );

    Serial.print(
        screenY
    );

    Serial.print(
        " Z="
    );

    Serial.println(
        pressure
    );
}