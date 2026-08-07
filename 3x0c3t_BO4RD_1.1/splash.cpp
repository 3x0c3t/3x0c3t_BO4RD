#include "splash.h"

#include "display.h"
#include "logo.h"
#include "config.h"
#include "progress.h"


void showSplash()
{
    clearScreen();


    drawLogo(
        tft,
        60,
        100
    );


    centerText(
        "M4KE W1TH L0VE",
        180,
        2,
        TFT_CYAN
    );


    animateProgress(
        SPLASH_DELAY
    );
}