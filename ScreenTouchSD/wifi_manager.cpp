#include "wifi_manager.h"
#include "config.h"

#include <ESP8266WiFi.h>


// ============================================================
// ETAT WIFI
// ============================================================

bool wifiConnected = false;


// ============================================================
// CONNEXION WIFI
// ============================================================

bool wifiConnect()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[WIFI] INITIALISATION");
    Serial.println("================================");

    Serial.print("[WIFI] SSID : ");
    Serial.println(WIFI_SSID);

    Serial.println("[WIFI] Demarrage WiFi...");

    WiFi.mode(WIFI_STA);

    WiFi.hostname(
        HOSTNAME
    );

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );


    int attempt = 0;

    while (
        WiFi.status() != WL_CONNECTED &&
        attempt < 30
    )
    {
        attempt++;

        Serial.print(
            "[WIFI] Tentative "
        );

        Serial.print(
            attempt
        );

        Serial.println(
            " / 30"
        );

        delay(500);
    }


    if (
        WiFi.status() == WL_CONNECTED
    )
    {
        wifiConnected = true;

        Serial.println();
        Serial.println(
            "[WIFI] CONNECTE"
        );

        Serial.print(
            "[WIFI] IP : "
        );

        Serial.println(
            WiFi.localIP()
        );

        Serial.print(
            "[WIFI] RSSI : "
        );

        Serial.print(
            WiFi.RSSI()
        );

        Serial.println(
            " dBm"
        );

        return true;
    }


    wifiConnected = false;

    Serial.println();
    Serial.println(
        "[WIFI] ECHEC"
    );

    Serial.print(
        "[WIFI] Etat : "
    );

    Serial.println(
        WiFi.status()
    );

    return false;
}


// ============================================================
// ETAT CONNEXION
// ============================================================

bool wifiIsConnected()
{
    return (
        WiFi.status() == WL_CONNECTED
    );
}


// ============================================================
// ADRESSE IP
// ============================================================

String wifiGetIP()
{
    if (
        !wifiIsConnected()
    )
    {
        return "0.0.0.0";
    }

    return WiFi.localIP().toString();
}


// ============================================================
// SIGNAL WIFI
// ============================================================

int wifiGetRSSI()
{
    if (
        !wifiIsConnected()
    )
    {
        return 0;
    }

    return WiFi.RSSI();
}