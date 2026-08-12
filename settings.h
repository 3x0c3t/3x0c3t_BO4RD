#ifndef SETTINGS_H
#define SETTINGS_H

#include <TFT_eSPI.h>

// TFT | configuration
#define TFT_ROTATION 2
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320

// H1 | position et hauteur
#define H1_Y 0
#define H1_H 20

// H1 | Header1_BackgroundColor: TFT_GREEN
#define H1_BGC TFT_GREEN

// H1 | Header1_TextColor: TFT_BLACK
#define H1_TC TFT_BLACK

// H1_LOGO | Logo_BackgroundColor: TFT_BLACK
#define H1_LOGO_BGC TFT_BLACK

// H1_LOGO | Logo_TextColor: TFT_RED
#define H1_LOGO_TC TFT_RED

// H1_LOGO | Logo_BorderColor: TFT_GREEN
#define H1_LOGO_BC TFT_GREEN

// H1_SQUARE | Square_BackgroundColor: TFT_BLACK
#define H1_SQUARE_BGC TFT_BLACK

// H1_SQUARE | Square_BorderColor: TFT_DARKGREY
#define H1_SQUARE_BC TFT_DARKGREY

// H2 | position et hauteur
#define H2_Y 20
#define H2_H 20

// H2 | Header2_BackgroundColor: TFT_BLACK
#define H2_BGC TFT_BLACK

// H2 | Header2_TextColor: TFT_WHITE
#define H2_TC TFT_WHITE

// H2_MENU | position et largeur
#define H2_MENU_X 0
#define H2_MENU_W 50

// H2_MENU | Menu_BackgroundColor: 0x18E3
#define H2_MENU_BGC 0x18E3

// H2_MENU | Menu_BorderColor: TFT_DARKGREY
#define H2_MENU_BC TFT_DARKGREY

// H2_TITLE | position et largeur
#define H2_TITLE_X 50
#define H2_TITLE_W 140

// H2_TITLE | Title_BackgroundColor: TFT_BLACK
#define H2_TITLE_BGC TFT_BLACK

// H2_TITLE | Title_BorderColor: TFT_DARKGREY
#define H2_TITLE_BC TFT_DARKGREY

// H2_SETTINGS | position et largeur
#define H2_SETTINGS_X 190
#define H2_SETTINGS_W 50

// H2_SETTINGS | Settings_BackgroundColor: 0x18E3
#define H2_SETTINGS_BGC 0x18E3

// H2_SETTINGS | Settings_BorderColor: TFT_DARKGREY
#define H2_SETTINGS_BC TFT_DARKGREY

// H2 | ligne
#define H2_LINE_C TFT_DARKGREY

// CONTENT | position de départ
#define CONTENT_Y 40

// CONTENT | Content_BackgroundColor: TFT_BLACK
#define CONTENT_BGC TFT_BLACK

// BUTTON | dimensions
#define BUTTON_X 10
#define BUTTON_W 220
#define BUTTON_H 45
#define BUTTON_RADIUS 7
#define BUTTON_SPACING 8

// BUTTON | Button_BackgroundColor: 0x18E3
#define BUTTON_BGC 0x18E3

// BUTTON | Button_BorderColor: TFT_WHITE
#define BUTTON_BC TFT_WHITE

// BUTTON | TitleColor: TFT_WHITE
#define BUTTON_TITLE_C TFT_WHITE

// BUTTON_LEFT | carré gauche
#define BUTTON_LEFT_SQUARE_SIZE 18

// BUTTON_RIGHT | carrés droite
#define BUTTON_RIGHT_SQUARE_SIZE 12
#define BUTTON_RIGHT_MARGIN 8
#define BUTTON_RIGHT_SPACING 4

#endif