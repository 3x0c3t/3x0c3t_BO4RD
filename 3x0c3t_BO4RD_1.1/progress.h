#ifndef PROGRESS_H
#define PROGRESS_H

#include <Arduino.h>

void drawProgress(
    uint8_t percent
);

void animateProgress(
    unsigned long duration
);

#endif