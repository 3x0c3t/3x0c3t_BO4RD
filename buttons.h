#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

void buttonDraw(
  int16_t x,
  int16_t y,
  int16_t w,
  int16_t h,
  const char *title
);

void squareDraw(
  int16_t x,
  int16_t y,
  int16_t size
);

#endif