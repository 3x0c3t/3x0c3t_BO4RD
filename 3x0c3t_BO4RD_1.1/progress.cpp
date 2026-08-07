#include "progress.h"
#include "display.h"
#include "config.h"


void drawProgress(
    uint8_t percent
)
{
    if(percent > 100)
        percent = 100;


    int width = map(
        percent,
        0,
        100,
        0,
        SCREEN_WIDTH
    );


    tft.fillRect(
        0,
        PROGRESS_Y,
        SCREEN_WIDTH,
        PROGRESS_HEIGHT,
        TFT_BLACK
    );


    tft.fillRect(
        0,
        PROGRESS_Y,
        width,
        PROGRESS_HEIGHT,
        TFT_CYAN
    );
}



void animateProgress(
    unsigned long duration
)
{
    unsigned long start = millis();


    while(
        millis() - start < duration
    )
    {
        uint8_t percent = map(
            millis() - start,
            0,
            duration,
            0,
            100
        );


        drawProgress(
            percent
        );


        delay(20);
    }


    drawProgress(100);
}