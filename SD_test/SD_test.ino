#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// ============================================================
// TFT ILI9341
// ============================================================

#define TFT_CS   15   // D8
#define TFT_DC    2   // D4
#define TFT_RST  16   // D0

#define TFT_MOSI 13   // D7
#define TFT_MISO 12   // D6
#define TFT_SCK  14   // D5


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

  delay(1500);

  Serial.println();
  Serial.println("================================");
  Serial.println("TEST TFT ILI9341 SEUL");
  Serial.println("================================");

  Serial.println("GPIO TFT :");
  Serial.println("CS  = GPIO15 / D8");
  Serial.println("DC  = GPIO2  / D4");
  Serial.println("RST = GPIO16 / D0");
  Serial.println("SCK = GPIO14 / D5");
  Serial.println("MOSI= GPIO13 / D7");
  Serial.println("MISO= GPIO12 / D6");

  // ----------------------------------------------------------
  // CS
  // ----------------------------------------------------------

  pinMode(TFT_CS, OUTPUT);

  digitalWrite(
    TFT_CS,
    HIGH
  );

  // ----------------------------------------------------------
  // SPI
  // ----------------------------------------------------------

  Serial.println();
  Serial.println("Initialisation SPI...");

  SPI.begin();

  Serial.println("SPI OK");

  // ----------------------------------------------------------
  // TFT
  // ----------------------------------------------------------

  Serial.println();
  Serial.println("Initialisation TFT...");

  tft.begin();

  Serial.println("TFT begin OK");

  // ----------------------------------------------------------
  // ROTATION
  // ----------------------------------------------------------

  tft.setRotation(0);

  Serial.println("Rotation = 0");

  // ----------------------------------------------------------
  // TEST COULEUR
  // ----------------------------------------------------------

  Serial.println();
  Serial.println("Test ROUGE");

  tft.fillScreen(
    ILI9341_RED
  );

  delay(2000);


  Serial.println("Test VERT");

  tft.fillScreen(
    ILI9341_GREEN
  );

  delay(2000);


  Serial.println("Test BLEU");

  tft.fillScreen(
    ILI9341_BLUE
  );

  delay(2000);


  Serial.println("Test BLANC");

  tft.fillScreen(
    ILI9341_WHITE
  );

  delay(2000);


  // ----------------------------------------------------------
  // TEST TEXTE
  // ----------------------------------------------------------

  Serial.println("Test texte");

  tft.fillScreen(
    ILI9341_BLACK
  );

  tft.setTextColor(
    ILI9341_WHITE
  );

  tft.setTextSize(2);

  tft.setCursor(
    10,
    20
  );

  tft.println(
    "3x0c3t"
  );

  tft.setTextSize(1);

  tft.setCursor(
    10,
    60
  );

  tft.println(
    "ILI9341 TEST"
  );

  tft.setCursor(
    10,
    80
  );

  tft.println(
    "ESP8266"
  );

  tft.setCursor(
    10,
    100
  );

  tft.println(
    "SPI OK"
  );

  tft.setCursor(
    10,
    120
  );

  tft.println(
    "TFT OK"
  );

  Serial.println();
  Serial.println("================================");
  Serial.println("FIN TEST TFT");
  Serial.println("================================");
}


// ============================================================
// LOOP
// ============================================================

void loop()
{
}