#include "wifi_manager.h"
#include "config.h"

#include <ESP8266WiFi.h>


// =====================================================
// INITIALISATION WIFI
// =====================================================

void wifiInit()
{
    Serial.println();
    Serial.println(
        "Connexion WiFi..."
    );

    WiFi.mode(
        WIFI_STA
    );

    WiFi.hostname(
        HOSTNAME
    );

    WiFi.begin(
        WIFI_SSID,
        WIFI_PASSWORD
    );


    unsigned long start =
        millis();


    while (
        WiFi.status() != WL_CONNECTED &&
        millis() - start < 15000
    )
    {
        delay(500);

        Serial.print(
            "."
        );
    }

    Serial.println();


    if (
        WiFi.status() == WL_CONNECTED
    )
    {
        Serial.println(
            "WiFi : CONNECTE"
        );

        Serial.print(
            "SSID : "
        );

        Serial.println(
            WiFi.SSID()
        );

        Serial.print(
            "IP : "
        );

        Serial.println(
            WiFi.localIP()
        );

        Serial.print(
            "MAC : "
        );

        Serial.println(
            WiFi.macAddress()
        );

        Serial.print(
            "RSSI : "
        );

        Serial.println(
            WiFi.RSSI()
        );
    }
    else
    {
        Serial.println(
            "WiFi : NON CONNECTE"
        );
    }
}


// =====================================================
// CONNECTE
// =====================================================

bool wifiConnected()
{
    return (
        WiFi.status() ==
        WL_CONNECTED
    );
}


// =====================================================
// SSID
// =====================================================

String wifiSSID()
{
    if (
        wifiConnected()
    )
    {
        return WiFi.SSID();
    }

    return "--";
}


// =====================================================
// IP
// =====================================================

String wifiIP()
{
    if (
        wifiConnected()
    )
    {
        return WiFi.localIP().toString();
    }

    return "--";
}


// =====================================================
// MAC
// =====================================================

String wifiMAC()
{
    return WiFi.macAddress();
}


// =====================================================
// RSSI
// =====================================================

int wifiRSSI()
{
    if (
        wifiConnected()
    )
    {
        return WiFi.RSSI();
    }

    return 0;
}


// =====================================================
// STATUS
// =====================================================

String wifiStatus()
{
    if (
        wifiConnected()
    )
    {
        return "CONNECTE";
    }

    return "NON CONNECTE";
}