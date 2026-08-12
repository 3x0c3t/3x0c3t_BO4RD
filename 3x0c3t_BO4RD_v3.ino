#include <Arduino.h>

#include "display.h"
#include "menu.h"

// ============================================================
// 3x0c3t BO4RD v3.1
// ============================================================

void setup()
{
  Serial.begin(115200);

  delay(500);

  Serial.println();
  Serial.println("================================");
  Serial.println("       3x0c3t BO4RD v3.1");
  Serial.println("================================");
  Serial.println("[SYSTEM] ESP8266");

  displayInit();

  menuDraw();
}

void loop()
{
  delay(10);
}