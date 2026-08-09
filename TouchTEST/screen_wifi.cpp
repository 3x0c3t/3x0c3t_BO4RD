#include "screen_wifi.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "ui.h"

void screenWifi()
{
    tft.fillScreen(
        TFT_BLACK
    );

    drawHeader();

    tft.setTextColor(
        TFT_WHITE,
        TFT_BLACK
    );

    tft.setTextSize(2);

    tft.setCursor(
        10,
        50
    );

    tft.print(
        "WIFI"
    );

    tft.setTextSize(1);

    tft.setCursor(
        10,
        80
    );

    tft.print(
        "Connexion WiFi..."
    );

    tft.setCursor(
        10,
        100
    );

    tft.print(
        "SSID : N0wifiHere"
    );

    tft.setCursor(
        10,
        120
    );

    tft.print(
        "Etat : CONNECTE"
    );

    drawFooter();
}