#ifndef TOUCH_H
#define TOUCH_H

#include <Arduino.h>
#include <XPT2046_Touchscreen.h>

// =====================================================
// XPT2046
// =====================================================

#define TOUCH_CS  0     // GPIO0 / D3
#define TOUCH_IRQ 5     // GPIO5 / D1

// =====================================================
// Calibration réelle de TON écran
// =====================================================

#define TOUCH_RAW_X_MIN 388
#define TOUCH_RAW_X_MAX 3701

#define TOUCH_RAW_Y_MIN 477
#define TOUCH_RAW_Y_MAX 3794

// =====================================================
// Objet tactile
// =====================================================

extern XPT2046_Touchscreen ts;

// =====================================================
// Initialisation
// =====================================================

void touchInit();

// =====================================================
// Lecture tactile
// =====================================================

bool touchRead(
    int16_t &screenX,
    int16_t &screenY,
    uint16_t &pressure
);

// =====================================================
// Affichage debug
// =====================================================

void touchDebug(
    int16_t screenX,
    int16_t screenY,
    uint16_t pressure
);

#endif