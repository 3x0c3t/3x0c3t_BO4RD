#include "sd_browser.h"
#include "config.h"

#include <SPI.h>
#include <SD.h>


// ============================================================
// ETAT SD
// ============================================================

bool sdReady = false;


// ============================================================
// INITIALISATION SD
// ============================================================

bool sdInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[SD] INITIALISATION");
    Serial.println("================================");

    Serial.print("[SD] CS = GPIO ");
    Serial.println(SD_CS_PIN);

    Serial.println(
        "[SD] Initialisation SD.begin()..."
    );


    pinMode(
        SD_CS_PIN,
        OUTPUT
    );

    digitalWrite(
        SD_CS_PIN,
        HIGH
    );


    if (
        !SD.begin(
            SD_CS_PIN
        )
    )
    {
        sdReady = false;

        Serial.println(
            "[SD] INITIALISATION ECHEC"
        );

        return false;
    }


    sdReady = true;

    Serial.println(
        "[SD] INITIALISATION OK"
    );

    return true;
}


// ============================================================
// ETAT SD
// ============================================================

bool sdIsReady()
{
    return sdReady;
}


// ============================================================
// AFFICHAGE RACINE
// ============================================================

void sdShowRoot()
{
    if (
        !sdReady
    )
    {
        Serial.println(
            "[SD] Carte non disponible"
        );

        return;
    }


    Serial.println();
    Serial.println(
        "================================"
    );

    Serial.println(
        "[SD] CONTENU DE LA RACINE"
    );

    Serial.println(
        "================================"
    );


    fs::File root =
        SD.open(
            "/"
        );


    if (
        !root
    )
    {
        Serial.println(
            "[SD] Impossible d'ouvrir /"
        );

        return;
    }


    if (
        !root.isDirectory()
    )
    {
        Serial.println(
            "[SD] / n'est pas un dossier"
        );

        root.close();

        return;
    }


    fs::File entry =
        root.openNextFile();


    while (
        entry
    )
    {
        Serial.print(
            "[SD] "
        );


        if (
            entry.isDirectory()
        )
        {
            Serial.print(
                "[DOSSIER] "
            );
        }
        else
        {
            Serial.print(
                "[FICHIER] "
            );
        }


        Serial.print(
            entry.name()
        );


        if (
            !entry.isDirectory()
        )
        {
            Serial.print(
                " ("
            );

            Serial.print(
                entry.size()
            );

            Serial.print(
                " octets)"
            );
        }


        Serial.println();


        entry.close();


        entry =
            root.openNextFile();
    }


    root.close();


    Serial.println(
        "[SD] Lecture racine terminee"
    );
}