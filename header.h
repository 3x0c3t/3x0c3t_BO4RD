#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>

void header1Draw();
void header2Draw(const char *title);

bool header2MenuPressed(int16_t x, int16_t y);
bool header2SettingsPressed(int16_t x, int16_t y);

#endif