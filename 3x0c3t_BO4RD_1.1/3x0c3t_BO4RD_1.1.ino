#include "display.h"
#include "screens.h"
#include "wifi_manager.h"
#include "heure.h"
#include "meteo.h"
#include "config.h"


unsigned long screenTimer = 0;
unsigned long clockTimer = 0;
unsigned long weatherTimer = 0;


uint8_t currentScreen = 0;



void setup()
{
    Serial.begin(115200);


    displayInit();


    showSplash();


    wifiConnect();


    initClock();


    initWeather();

    updateWeather();



    showClockScreen();



    screenTimer = millis();
    clockTimer = millis();
    weatherTimer = millis();

}



void loop()
{

    unsigned long now = millis();



    // ==========================
    // Mise à jour horloge chaque seconde
    // ==========================

    if(now - clockTimer >= CLOCK_REFRESH_TIME)
    {

        clockTimer = now;


        if(currentScreen == 0)
        {
            updateClockScreen();
        }

    }




    // ==========================
    // Mise à jour météo
    // ==========================

    if(now - weatherTimer >= WEATHER_REFRESH_TIME)
    {

        weatherTimer = now;


        updateWeather();

    }




    // ==========================
    // Gestion changement écran
    // ==========================

    if(currentScreen == 0)
    {

        if(now - screenTimer >= CLOCK_SCREEN_TIME)
        {

            currentScreen = 1;

            screenTimer = now;


            showWeatherScreen();

        }

    }
    else
    {

        if(now - screenTimer >= WEATHER_SCREEN_TIME)
        {

            currentScreen = 0;

            screenTimer = now;


            showClockScreen();

        }

    }




    delay(50);

}