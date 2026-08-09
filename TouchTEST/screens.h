#ifndef SCREENS_H
#define SCREENS_H

#include <Arduino.h>

// =====================================================
// IDENTIFIANTS DES ECRANS
// =====================================================

enum ScreenID
{
    SCREEN_SPLASH = 0,
    SCREEN_WIFI,
    SCREEN_HOME,
    SCREEN_METEO,
    SCREEN_SYSTEM
};

// =====================================================
// INITIALISATION
// =====================================================

void screensInit();

// =====================================================
// AFFICHAGE
// =====================================================

void screensShow(ScreenID screen);

// =====================================================
// ECRAN ACTUEL
// =====================================================

ScreenID screensGetCurrent();

#endif