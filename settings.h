#ifndef SETTINGS_H
#define SETTINGS_H

#include <TFT_eSPI.h>

// ============================================================
// 3x0c3t BO4RD v3.1
// SETTINGS
// ============================================================

// ============================================================
// TFT
// ============================================================

#define TFT_ROTATION 2

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 320

// ============================================================
// COULEURS GENERALES
// ============================================================

#define COLOR_BACKGROUND TFT_BLACK

// ============================================================
// HEADER 1
// Hauteur totale : 10 px
// ============================================================

#define H1_Y 0
#define H1_H 10

// ------------------------------------------------------------
// H1B1 : HEURE
// HH:MM:SS
// ------------------------------------------------------------

#define H1B1_X 0
#define H1B1_Y H1_Y
#define H1B1_W 60
#define H1B1_H H1_H

#define H1B1_BGC TFT_GREEN
#define H1B1_BC  TFT_GREEN
#define H1B1_TC  TFT_BLACK

#define H1B1_TEXT_SIZE 1

// ------------------------------------------------------------
// H1B2 : DATE
// AAAA:MM:SS
// ------------------------------------------------------------

#define H1B2_X 60
#define H1B2_Y H1_Y
#define H1B2_W 70
#define H1B2_H H1_H

#define H1B2_BGC TFT_GREEN
#define H1B2_BC  TFT_GREEN
#define H1B2_TC  TFT_BLACK

#define H1B2_TEXT_SIZE 1

// ------------------------------------------------------------
// H1B3 : LOGO
// -3X0C3T-
// ------------------------------------------------------------

#define H1B3_X 130
#define H1B3_Y H1_Y
#define H1B3_W 50
#define H1B3_H H1_H

#define H1B3_BGC TFT_BLACK
#define H1B3_BC  TFT_GREEN
#define H1B3_TC  TFT_RED

#define H1B3_TEXT_SIZE 1

// ------------------------------------------------------------
// H1B4 : STATUS
// Bloc de carrés
// ------------------------------------------------------------

#define H1B4_X 180
#define H1B4_Y H1_Y
#define H1B4_W 60
#define H1B4_H H1_H

#define H1B4_BGC TFT_BLACK
#define H1B4_BC  TFT_DARKGREY
#define H1B4_TC  TFT_WHITE

// Carrés H1B4

#define H1B4_SQUARE_SIZE     6
#define H1B4_SQUARE_SPACING  2
#define H1B4_SQUARE_MARGIN   2
#define H1B4_SQUARE_COUNT    4

#define H1B4_SQUARE_BGC TFT_BLACK
#define H1B4_SQUARE_BC  TFT_DARKGREY

// ============================================================
// HEADER 2
// Hauteur totale : 20 px
// ============================================================

#define H2_Y 10
#define H2_H 20

// ------------------------------------------------------------
// H2B1 : MENU
// largeur fixe 50 px
// ------------------------------------------------------------

#define H2B1_X 0
#define H2B1_Y H2_Y
#define H2B1_W 50
#define H2B1_H H2_H

#define H2B1_BGC 0x18E3
#define H2B1_BC  TFT_DARKGREY
#define H2B1_TC  TFT_WHITE

#define H2B1_TEXT_SIZE 1

// ------------------------------------------------------------
// H2B2 : TITRE
// largeur restante
// ------------------------------------------------------------

#define H2B2_X (H2B1_X + H2B1_W)
#define H2B2_Y H2_Y

#define H2B2_W (SCREEN_WIDTH - H2B1_W - H2B3_W)
#define H2B2_H H2_H

#define H2B2_BGC TFT_BLACK
#define H2B2_BC  TFT_DARKGREY
#define H2B2_TC  TFT_WHITE

#define H2B2_TEXT_SIZE 1

// ------------------------------------------------------------
// H2B3 : SETTINGS
// largeur fixe 50 px
// ------------------------------------------------------------

#define H2B3_X (SCREEN_WIDTH - H2B3_W)
#define H2B3_Y H2_Y

#define H2B3_W 50
#define H2B3_H H2_H

#define H2B3_BGC 0x18E3
#define H2B3_BC  TFT_DARKGREY
#define H2B3_TC  TFT_WHITE

#define H2B3_TEXT_SIZE 1

// ------------------------------------------------------------
// Ligne basse Header 2
// ------------------------------------------------------------

#define H2_LINE_C TFT_DARKGREY

// ============================================================
// CONTENU
// ============================================================

#define CONTENT_Y 30

#define CONTENT_BGC TFT_BLACK

// ============================================================
// BOUTONS
// ============================================================

#define BUTTON_X 10
#define BUTTON_Y CONTENT_Y

#define BUTTON_W 220
#define BUTTON_H 45

#define BUTTON_RADIUS 7
#define BUTTON_SPACING 8

// ------------------------------------------------------------
// Couleurs boutons
// ------------------------------------------------------------

#define BUTTON_BGC 0x18E3
#define BUTTON_BC  TFT_WHITE
#define BUTTON_TC  TFT_WHITE

// ------------------------------------------------------------
// Carré gauche
// ------------------------------------------------------------

#define BUTTON_LEFT_SQUARE_SIZE 18

// ------------------------------------------------------------
// Carrés droite
// ------------------------------------------------------------

#define BUTTON_RIGHT_SQUARE_SIZE 12
#define BUTTON_RIGHT_MARGIN      8
#define BUTTON_RIGHT_SPACING     4

// ============================================================
// SQUARE GENERIQUE
// ============================================================

#define SQUARE_BGC TFT_BLACK
#define SQUARE_BC  TFT_DARKGREY

#endif