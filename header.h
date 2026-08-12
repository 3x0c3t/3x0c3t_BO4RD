#ifndef HEADER_H
#define HEADER_H

#include <Arduino.h>


// ============================================================
// HEADER 1
// ============================================================

void header1Draw();


// ============================================================
// HEADER 2
// ============================================================

void header2Draw(
  const char *title
);


// ============================================================
// ICÔNE MENU BURGER
// ============================================================

void drawBurgerIcon(
  int16_t centerX,
  int16_t centerY
);


// ============================================================
// TOUCH - HEADER 2
// ============================================================

bool header2MenuPressed(
  int16_t x,
  int16_t y
);


bool header2SettingsPressed(
  int16_t x,
  int16_t y
);


bool header2TitlePressed(
  int16_t x,
  int16_t y
);


#endif