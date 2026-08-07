#include "logo.h"


const uint16_t logoBitmap[] PROGMEM =
{

    // COLLER ICI LE TABLEAU RGB565

};



void drawLogo(
    TFT_eSPI &tft,
    int16_t x,
    int16_t y
)
{
    tft.pushImage(
        x,
        y,
        LOGO_WIDTH,
        LOGO_HEIGHT,
        logoBitmap
    );
}