#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <ArduinoJson.h>
#include <SD.h>

#include "config.h"

extern TFT_eSPI tft;

// ============================================================
// ECRAN
// ============================================================

void displayInit();

// ============================================================
// SD
// ============================================================

bool sdInit();
void listSDFiles();
bool checkSDPages();

// ============================================================
// JSON
// ============================================================

bool loadJSONPage(uint8_t page);
bool loadJSONFile(const char *filename);

// ============================================================
// AFFICHAGE
// ============================================================

void drawJSONPage(JsonDocument &doc);
void drawJSONObject(JsonObject object);
void drawJSONText(JsonObject object);
void drawJSONShape(JsonObject object);
void drawJSONLine(JsonObject object);

// ============================================================
// UTILITAIRES
// ============================================================

uint16_t getColor(const char *color);

void drawPage(uint8_t page);

#endif