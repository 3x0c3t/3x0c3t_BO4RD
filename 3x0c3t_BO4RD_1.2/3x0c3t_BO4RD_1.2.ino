#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// ============================================================
// 3x0c3t_BO4RD_1.1
// TFT ILI9341 240x320
// ============================================================

// TFT
#define TFT_CS   15   // D8
#define TFT_DC    2   // D4
#define TFT_RST  16   // D0

// SPI ESP8266
// MOSI = GPIO13 / D7
// MISO = GPIO12 / D6
// SCK  = GPIO14 / D5

Adafruit_ILI9341 tft(
  TFT_CS,
  TFT_DC,
  TFT_RST
);

// ============================================================
// SETUP
// ============================================================

void setup()
{
  Serial.begin(115200);

  delay(2000);

  Serial.println();
  Serial.println("================================");
  Serial.println("  3x0c3t_BO4RD_1.1");
  Serial.println("  TEST TFT ILI9341");
  Serial.println("================================");

  // ----------------------------------------------------------
  // Broches
  // ----------------------------------------------------------

  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_RST, OUTPUT);

  digitalWrite(TFT_CS, HIGH);

  // ----------------------------------------------------------
  // SPI
  // ----------------------------------------------------------

  Serial.println("[SPI] Initialisation");

  SPI.begin();

  delay(100);

  // ----------------------------------------------------------
  // RESET HARDWARE TFT
  // ----------------------------------------------------------

  Serial.println("[TFT] Reset");

  digitalWrite(TFT_RST, HIGH);
  delay(50);

  digitalWrite(TFT_RST, LOW);
  delay(200);

  digitalWrite(TFT_RST, HIGH);
  delay(200);

  // ----------------------------------------------------------
  // ILI9341
  // ----------------------------------------------------------

  Serial.println("[TFT] begin()");

  tft.begin();

  delay(500);

  Serial.println("[TFT] begin OK");

  // ----------------------------------------------------------
  // Rotation
  // ----------------------------------------------------------

  tft.setRotation(0);

  // ==========================================================
  // TEST 1 : ROUGE
  // ==========================================================

  Serial.println("[TFT] ROUGE");

  tft.fillScreen(ILI9341_RED);

  delay(2000);

  // ==========================================================
  // TEST 2 : VERT
  // ==========================================================

  Serial.println("[TFT] VERT");

  tft.fillScreen(ILI9341_GREEN);

  delay(2000);

  // ==========================================================
  // TEST 3 : BLEU
  // ==========================================================

  Serial.println("[TFT] BLEU");

  tft.fillScreen(ILI9341_BLUE);

  delay(2000);

  // ==========================================================
  // TEST 4 : NOIR + TEXTE
  // ==========================================================

  Serial.println("[TFT] TEXTE");

  tft.fillScreen(ILI9341_BLACK);

  // ----------------------------------------------------------
  // Bordure
  // ----------------------------------------------------------

  tft.drawRect(
    0,
    0,
    240,
    320,
    ILI9341_RED
  );

  // ----------------------------------------------------------
  // Texte
  // ----------------------------------------------------------

  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);

  tft.setCursor(20, 30);
  tft.println("3x0c3t");

  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);

  tft.setCursor(20, 80);
  tft.println("BO4RD 1.1");

  tft.setTextColor(ILI9341_CYAN);

  tft.setCursor(20, 120);
  tft.println("ILI9341");

  tft.setTextColor(ILI9341_YELLOW);

  tft.setCursor(20, 160);
  tft.println("240 x 320");

  // ----------------------------------------------------------
  // GPIO
  // ----------------------------------------------------------

  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(1);

  tft.setCursor(20, 210);
  tft.println("CS  = GPIO15 / D8");

  tft.setCursor(20, 225);
  tft.println("DC  = GPIO2  / D4");

  tft.setCursor(20, 240);
  tft.println("RST = GPIO16 / D0");

  tft.setCursor(20, 255);
  tft.println("MOSI = GPIO13 / D7");

  tft.setCursor(20, 270);
  tft.println("SCK  = GPIO14 / D5");

  tft.setCursor(20, 285);
  tft.println("MISO = GPIO12 / D6");

  // ----------------------------------------------------------
  // Rectangle final
  // ----------------------------------------------------------

  tft.drawRect(
    5,
    5,
    230,
    310,
    ILI9341_BLUE
  );

  Serial.println();
  Serial.println("================================");
  Serial.println("  AFFICHAGE TERMINE");
  Serial.println("================================");
}

// ============================================================
// LOOP
// ============================================================

void loop()
{
  Serial.println("[LOOP] TFT ACTIF");

  delay(2000);
}