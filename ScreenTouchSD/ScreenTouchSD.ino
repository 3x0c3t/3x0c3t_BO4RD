
#include "config.h"
#include "display.h"
#include "splash.h"


void setup()
{
    Serial.begin(
        115200
    );

    delay(500);


    Serial.println();
    Serial.println();

    Serial.println(
        "################################"
    );

    Serial.println(
        "# 3x0c3t BO4RD"
    );

    Serial.println(
        "# ScreenTouchSD"
    );

    Serial.println(
        "# TFT / SPLASH TEST"
    );

    Serial.println(
        "################################"
    );


    // ========================================================
    // TFT
    // ========================================================

    displayInit();


    // ========================================================
    // SPLASH
    // ========================================================

    showSplash();


    // ========================================================
    // FIN ETAPE 1
    // ========================================================

    Serial.println();

    Serial.println(
        "[SYSTEME] Splash termine"
    );

    Serial.println(
        "[SYSTEME] Etape suivante : WIFI"
    );
}


void loop()
{
    delay(100);
}
EOF