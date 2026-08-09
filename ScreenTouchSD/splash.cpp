cat > splash.cpp <<'EOF'
#include "splash.h"
#include "display.h"
#include "config.h"


void showSplash()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("[SPLASH] DEMARRAGE");
    Serial.println("================================");


    clearScreen();

    drawProgress(0);


    centerText(
        "3x0c3t",
        100,
        4,
        COLOR_PRIMARY
    );


    centerText(
        "BO4RD",
        145,
        2,
        COLOR_TEXT
    );


    centerText(
        "M4KE W1TH L0VE",
        190,
        2,
        COLOR_PRIMARY
    );


    centerText(
        "SYSTEM",
        225,
        2,
        COLOR_TEXT
    );


    // --------------------------------------------------------
    // Animation
    // --------------------------------------------------------

    for (
        int percent = 0;
        percent <= 100;
        percent += 4
    )
    {
        drawProgress(
            percent
        );

        delay(
            SPLASH_DELAY / 25
        );
    }


    Serial.println(
        "[SPLASH] TERMINE"
    );
}
EOF