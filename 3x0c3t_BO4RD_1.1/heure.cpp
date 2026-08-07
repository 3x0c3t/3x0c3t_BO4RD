#include "heure.h"
#include <time.h>
#include "config.h"

void initClock()
{
    configTime(
        GMT_OFFSET,
        DAYLIGHT_OFFSET,
        NTP_SERVER
    );
}


void drawHeaderClock(
    TFT_eSPI &tft,
    int16_t x,
    int16_t y
)
{
    struct tm timeinfo;

    if(!getLocalTime(&timeinfo))
        return;

    char buffer[32];

    const char* jours[] =
    {
        "DIM",
        "LUN",
        "MAR",
        "MER",
        "JEU",
        "VEN",
        "SAM"
    };

    sprintf(
        buffer,
        "%02d:%02d:%02d %s %02d/%02d/%04d",
        timeinfo.tm_hour,
        timeinfo.tm_min,
        timeinfo.tm_sec,
        jours[timeinfo.tm_wday],
        timeinfo.tm_mday,
        timeinfo.tm_mon+1,
        timeinfo.tm_year+1900
    );

    tft.setTextDatum(MC_DATUM);
    tft.setTextFont(2);
    tft.setTextColor(
        TFT_WHITE,
        TFT_BLACK
    );

    tft.drawString(
        buffer,
        x,
        y,
        2
    );
}


void drawBigClock(
    TFT_eSPI &tft,
    int16_t x,
    int16_t y
)
{
    struct tm timeinfo;

    if(!getLocalTime(&timeinfo))
        return;

    char heure[12];
    char date[24];

    const char* jours[] =
    {
        "DIM",
        "LUN",
        "MAR",
        "MER",
        "JEU",
        "VEN",
        "SAM"
    };

    sprintf(
        heure,
        "%02d:%02d:%02d",
        timeinfo.tm_hour,
        timeinfo.tm_min,
        timeinfo.tm_sec
    );

    sprintf(
        date,
        "%s %02d/%02d/%04d",
        jours[timeinfo.tm_wday],
        timeinfo.tm_mday,
        timeinfo.tm_mon+1,
        timeinfo.tm_year+1900
    );

    tft.setTextDatum(MC_DATUM);

    // Grande heure
    tft.setTextFont(4);
    tft.setTextSize(2);
    tft.setTextColor(
        TFT_CYAN,
        TFT_BLACK
    );

    tft.drawString(
        heure,
        x,
        y
    );

    // Date dessous
    tft.setTextSize(1);
    tft.setTextFont(2);
    tft.setTextColor(
        TFT_WHITE,
        TFT_BLACK
    );

    tft.drawString(
        date,
        x,
        y + 55
    );
}