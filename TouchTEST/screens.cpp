#include "screens.h"

// =====================================================
// ECRANS
// =====================================================

#include "screen_splash.h"
#include "screen_wifi.h"
#include "screen_home.h"
#include "screen_meteo.h"
#include "screen_system.h"

// =====================================================
// ECRAN ACTUEL
// =====================================================

static ScreenID currentScreen = SCREEN_SPLASH;

// =====================================================
// INITIALISATION
// =====================================================

void screensInit()
{
    currentScreen = SCREEN_SPLASH;
}

// =====================================================
// RECUPERER ECRAN ACTUEL
// =====================================================

ScreenID screensGetCurrent()
{
    return currentScreen;
}

// =====================================================
// AFFICHER UN ECRAN
// =====================================================

void screensShow(ScreenID screen)
{
    currentScreen = screen;

    Serial.print("Affichage ecran : ");

    switch (screen)
    {
        case SCREEN_SPLASH:

            Serial.println("SPLASH");

            screenSplash();

            break;


        case SCREEN_WIFI:

            Serial.println("WIFI");

            screenWifi();

            break;


        case SCREEN_HOME:

            Serial.println("HOME");

            screenHome();

            break;


        case SCREEN_METEO:

            Serial.println("METEO");

            screenMeteo();

            break;


        case SCREEN_SYSTEM:

            Serial.println("SYSTEM");

            screenSystem();

            break;
    }
}