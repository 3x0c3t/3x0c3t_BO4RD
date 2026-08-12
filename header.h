#ifndef HEADER_H
#define HEADER_H

#include <Arduino.h>

void header1Draw();
void header2Draw(const char *title);

void squareDrawHeader(
  int16_t x,
  int16_t y,
  int16_t size
);

bool header2MenuPressed(
  int16_t x,
  int16_t y
);

bool header2SettingsPressed(
  int16_t x,
  int16_t y
);

#endif