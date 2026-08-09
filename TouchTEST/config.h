#ifndef CONFIG_H
#define CONFIG_H

#include <TFT_eSPI.h>

// =====================================================
// ECRAN
// =====================================================

#define TFT_ROTATION 2

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320


// =====================================================
// COULEURS
// =====================================================

#define COLOR_BACKGROUND TFT_BLACK
#define COLOR_TEXT       TFT_WHITE
#define COLOR_PRIMARY    TFT_CYAN
#define COLOR_OK         TFT_GREEN
#define COLOR_ERROR      TFT_RED
#define COLOR_WARNING    TFT_YELLOW
#define COLOR_BOX        TFT_CYAN
#define COLOR_GREY      TFT_DARKGREY


// =====================================================
// HEADER
// =====================================================

#define HEADER_Y        5
#define HEADER_HEIGHT   20
#define HEADER_LINE_Y   (HEADER_Y + HEADER_HEIGHT)


// =====================================================
// CARRES HEADER
// =====================================================

#define STATUS_BOX_SIZE 14
#define STATUS_BOX_GAP  3
#define STATUS_BOX_COUNT 4


// =====================================================
// FOOTER
// =====================================================

#define FOOTER_HEIGHT  35
#define FOOTER_Y       (SCREEN_HEIGHT - FOOTER_HEIGHT)


// =====================================================
// WIFI
// =====================================================

#define WIFI_SSID     "N0wifiHere"
#define WIFI_PASSWORD "@PassWeurd"

#define HOSTNAME      "3x0c3t-BO4RD"


// =====================================================
// NTP
// =====================================================

#define NTP_SERVER "pool.ntp.org"

#define GMT_OFFSET_SEC      3600
#define DAYLIGHT_OFFSET_SEC 3600


// =====================================================
// TEMPORISATIONS
// =====================================================

#define SPLASH_DELAY 3000

#define WIFI_SCREEN_TIME 5000

#define CLOCK_UPDATE_TIME 1000


#endif