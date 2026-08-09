cat > config.h <<'EOF'
#ifndef CONFIG_H
#define CONFIG_H

// ============================================================
// ECRAN TFT ILI9341
// ============================================================

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

#define TFT_ROTATION 2


// ============================================================
// BROCHES TFT
// ============================================================

#define TFT_CS_PIN   15   // D8
#define TFT_DC_PIN    2   // D4
#define TFT_RST_PIN  16   // D0


// ============================================================
// BUS SPI
// ============================================================

#define SPI_SCK_PIN  14   // D5
#define SPI_MISO_PIN 12   // D6
#define SPI_MOSI_PIN 13   // D7


// ============================================================
// XPT2046
// ============================================================

#define TOUCH_CS_PIN  0   // D3
#define TOUCH_IRQ_PIN 5   // D1


// ============================================================
// SD
// ============================================================

#define SD_CS_PIN 4       // D2


// ============================================================
// COULEURS
// ============================================================

#define COLOR_BACKGROUND TFT_BLACK
#define COLOR_TEXT       TFT_WHITE
#define COLOR_PRIMARY    TFT_CYAN
#define COLOR_OK         TFT_GREEN
#define COLOR_ERROR      TFT_RED
#define COLOR_WARNING    TFT_YELLOW
#define COLOR_LINE       TFT_DARKGREY


// ============================================================
// SPLASH
// ============================================================

#define SPLASH_DELAY 3000


// ============================================================
// WIFI
// ============================================================

#define WIFI_SSID     "N0wifiHere"
#define WIFI_PASSWORD "@PassWeurd"

#define HOSTNAME "3x0c3t-BO4RD"


#endif
EOF