#ifndef SETTINGS_H
#define SETTINGS_H

// ============================================================
// 3x0c3t BO4RD v3.1
// ESP8266 + TFT_eSPI + ILI9341
// ============================================================

// ------------------------------------------------------------
// TFT
// ------------------------------------------------------------

#define TFT_ROTATION 2


// ------------------------------------------------------------
// Écran
// ------------------------------------------------------------

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320


// ------------------------------------------------------------
// HEADER 1
// ------------------------------------------------------------

#define HEADER1_Y       0
#define HEADER1_HEIGHT  20


// ------------------------------------------------------------
// HEADER 2
// ------------------------------------------------------------

#define HEADER2_Y       20
#define HEADER2_HEIGHT 20


// ------------------------------------------------------------
// CONTENU
// ------------------------------------------------------------

#define CONTENT_Y 40


// ------------------------------------------------------------
// BOUTONS
// ------------------------------------------------------------

#define BUTTON_X        10
#define BUTTON_WIDTH    220
#define BUTTON_HEIGHT   45
#define BUTTON_RADIUS   7
#define BUTTON_SPACING  8


// ------------------------------------------------------------
// Carré gauche
// ------------------------------------------------------------

#define BUTTON_LEFT_SQUARE_SIZE 18


// ------------------------------------------------------------
// Carrés droits
// ------------------------------------------------------------

#define BUTTON_RIGHT_SQUARE_SIZE 12
#define BUTTON_RIGHT_MARGIN      8
#define BUTTON_RIGHT_SPACING     4


// ------------------------------------------------------------
// Couleurs
// ------------------------------------------------------------

#define COLOR_BACKGROUND    TFT_BLACK

#define COLOR_HEADER1_BG    TFT_GREEN
#define COLOR_HEADER1_TEXT  TFT_BLACK

#define COLOR_HEADER2_BG    TFT_BLACK
#define COLOR_HEADER2_TEXT  TFT_WHITE

#define COLOR_LINE          TFT_DARKGREY

#define COLOR_BUTTON_BG     0x18E3
#define COLOR_BUTTON_BORDER TFT_WHITE

#define COLOR_SQUARE_BG     TFT_BLACK
#define COLOR_SQUARE_BORDER TFT_DARKGREY

#define COLOR_TITLE         TFT_WHITE

#endif