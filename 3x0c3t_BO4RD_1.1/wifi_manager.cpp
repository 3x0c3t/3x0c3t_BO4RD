#include "wifi_manager.h"

#include <ESP8266WiFi.h>

#include "display.h"
#include "config.h"
#include "progress.h"


void wifiConnect()
{
    clearScreen();

    WiFi.hostname(
        HOSTNAME
    );

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );

    uint8_t progress=0;

    while(
        WiFi.status()!=WL_CONNECTED
    )
    {
        drawProgress(progress);

        centerText(
            "Connexion WIFI",
            100,
            2,
            TFT_WHITE
        );

        progress++;

        if(progress>100)
            progress=0;

        delay(200);
    }


    clearScreen();

    drawProgress(100);

    centerText(
        "CONNECTE",
        100,
        2,
        TFT_GREEN
    );


    tft.drawString(
        WiFi.localIP().toString(),
        SCREEN_WIDTH/2,
        140,
        2
    );

    delay(2000);
}