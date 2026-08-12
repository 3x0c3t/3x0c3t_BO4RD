#ifndef SETTINGS_H
#define SETTINGS_H

#include <TFT_eSPI.h>

// TFT | configuration
#define TFT_ROTATION 2
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

// HEADER1 | dimensions
#define H1_Y 0
#define H1_H 10

// H1B1 | heure
#define H1B1_X 0
#define H1B1_Y 0
#define H1B1_W 60
#define H1B1_H 10
#define H1B1_BGC TFT_GREEN
#define H1B1_TC TFT_BLACK
#define H1B1_BC TFT_GREEN
#define H1B1_TEXT_SIZE 1

// H1B2 | date
#define H1B2_X 60
#define H1B2_Y 0
#define H1B2_W 70
#define H1B2_H 10
#define H1B2_BGC TFT_GREEN
#define H1B2_TC TFT_BLACK
#define H1B2_BC TFT_GREEN
#define H1B2_TEXT_SIZE 1

// H1B3 | logo
#define H1B3_X 130
#define H1B3_Y 0
#define H1B3_W 50
#define H1B3_H 10
#define H1B3_BGC TFT_BLACK
#define H1B3_TC TFT_RED
#define H1B3_BC TFT_GREEN
#define H1B3_TEXT_SIZE 1

// H1B4 | status
#define H1B4_X 180
#define H1B4_Y 0
#define H1B4_W 60
#define H1B4_H 10
#define H1B4_BGC TFT_BLACK
#define H1B4_TC TFT_WHITE
#define H1B4_BC TFT_DARKGREY

// H1B4 | carrés
#define H1B4_SQUARE_SIZE 6
#define H1B4_SQUARE_SPACING 2
#define H1B4_SQUARE_MARGIN 2
#define H1B4_SQUARE_BGC TFT_BLACK
#define H1B4_SQUARE_BC TFT_DARKGREY
#define H1B4_SQUARE_COUNT 4

// HEADER2 | dimensions
#define H2_Y 10
#define H2_H 20

// H2B1 | menu
#define H2B1_X 0
#define H2B1_Y 10
#define H2B1_W 50
#define H2B1_H 20
#define H2B1_BGC 0x18E3
#define H2B1_BC TFT_DARKGREY
#define H2B1_TC TFT_WHITE
#define H2B1_TEXT_SIZE 1

// H2B2 | titre
#define H2B2_X 50
#define H2B2_Y 10
#define H2B2_W 140
#define H2B2_H 20
#define H2B2_BGC TFT_BLACK
#define H2B2_BC TFT_DARKGREY
#define H2B2_TC TFT_WHITE
#define H2B2_TEXT_SIZE 1

// H2B3 | settings
#define H2B3_X 190
#define H2B3_Y 10
#define H2B3_W 50
#define H2B3_H 20
#define H2B3_BGC 0x18E3
#define H2B3_BC TFT_DARKGREY
#define H2B3_TC TFT_WHITE
#define H2B3_TEXT_SIZE 1

// H2 | ligne
#define H2_LINE_C TFT_DARKGREY

// CONTENU | position
#define CONTENT_Y 30

// CONTENU | fond
#define CONTENT_BGC TFT_BLACK
#define COLOR_BACKGROUND TFT_BLACK

// BOUTONS | dimensions
#define BUTTON_X 10
#define BUTTON_Y CONTENT_Y
#define BUTTON_W 220
#define BUTTON_H 45
#define BUTTON_RADIUS 7
#define BUTTON_SPACING 8

// BOUTONS | couleurs
#define BUTTON_BGC 0x18E3
#define BUTTON_BC TFT_WHITE
#define BUTTON_TC TFT_WHITE
#define BUTTON_TITLE_C TFT_WHITE

// BOUTONS | carré gauche
#define BUTTON_LEFT_SQUARE_SIZE 18

// BOUTONS | carrés droite
#define BUTTON_RIGHT_SQUARE_SIZE 12
#define BUTTON_RIGHT_MARGIN 8
#define BUTTON_RIGHT_SPACING 4

// SQUARE | couleurs
#define SQUARE_BGC TFT_BLACK
#define SQUARE_BC TFT_DARKGREY

#endif