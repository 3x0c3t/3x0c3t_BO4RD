#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <TFT_eSPI.h>

// ============================================================
// CONFIGURATION
// ============================================================

// CS de la carte SD
// GPIO4 = D2 sur NodeMCU
#define SD_CS_PIN 4

// Rotation écran
#define TFT_ROTATION 1

// Couleurs
#define COLOR_BACKGROUND TFT_BLACK
#define COLOR_TEXT       TFT_WHITE
#define COLOR_OK         TFT_GREEN
#define COLOR_ERROR      TFT_RED
#define COLOR_INFO       TFT_CYAN
#define COLOR_WARNING    TFT_YELLOW

// ============================================================
// OBJET TFT
// ============================================================

TFT_eSPI tft = TFT_eSPI();

// ============================================================
// FONCTIONS
// ============================================================

void printBoth(const char *text, uint16_t color = COLOR_TEXT)
{
    Serial.println(text);

    tft.setTextColor(color, COLOR_BACKGROUND);
    tft.println(text);
}


// ============================================================
// TEST CREATION / ECRITURE FICHIER
// ============================================================

bool testWrite()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("TEST ECRITURE SD");
    Serial.println("================================");

    tft.println();
    tft.setTextColor(COLOR_INFO, COLOR_BACKGROUND);
    tft.println("TEST ECRITURE SD");

    File file = SD.open("/sd_test.txt", FILE_WRITE);

    if (!file)
    {
        Serial.println("ERREUR : impossible de creer /sd_test.txt");

        tft.setTextColor(COLOR_ERROR, COLOR_BACKGROUND);
        tft.println("ERREUR ECRITURE");

        return false;
    }

    Serial.println("Fichier ouvert en ecriture.");

    file.println("3x0c3t SD TEST");
    file.println("ESP8266");
    file.println("TFT Designer");
    file.println("Carte SD fonctionnelle.");

    file.close();

    Serial.println("Donnees ecrites.");
    Serial.println("Fichier ferme.");

    tft.setTextColor(COLOR_OK, COLOR_BACKGROUND);
    tft.println("ECRITURE OK");

    return true;
}


// ============================================================
// TEST LECTURE FICHIER
// ============================================================

bool testRead()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("TEST LECTURE SD");
    Serial.println("================================");

    tft.println();
    tft.setTextColor(COLOR_INFO, COLOR_BACKGROUND);
    tft.println("TEST LECTURE");

    File file = SD.open("/sd_test.txt", FILE_READ);

    if (!file)
    {
        Serial.println("ERREUR : impossible d'ouvrir /sd_test.txt");

        tft.setTextColor(COLOR_ERROR, COLOR_BACKGROUND);
        tft.println("ERREUR LECTURE");

        return false;
    }

    Serial.print("Taille du fichier : ");
    Serial.print(file.size());
    Serial.println(" octets");

    tft.setTextColor(COLOR_TEXT, COLOR_BACKGROUND);
    tft.print("Taille : ");
    tft.print(file.size());
    tft.println(" octets");

    Serial.println();
    Serial.println("CONTENU :");
    Serial.println("--------------------------------");

    while (file.available())
    {
        String line = file.readStringUntil('\n');

        Serial.println(line);

        // Affichage limité pour ne pas remplir l'écran
        if (line.length() > 0)
        {
            tft.setTextColor(COLOR_TEXT, COLOR_BACKGROUND);
            tft.println(line);
        }
    }

    Serial.println("--------------------------------");

    file.close();

    Serial.println("Lecture terminee.");

    tft.setTextColor(COLOR_OK, COLOR_BACKGROUND);
    tft.println("LECTURE OK");

    return true;
}


// ============================================================
// LISTE DES FICHIERS
// ============================================================

void listFiles()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("CONTENU CARTE SD");
    Serial.println("================================");

    tft.println();
    tft.setTextColor(COLOR_INFO, COLOR_BACKGROUND);
    tft.println("FICHIERS SD");

    File root = SD.open("/");

    if (!root)
    {
        Serial.println("ERREUR : impossible d'ouvrir /");

        tft.setTextColor(COLOR_ERROR, COLOR_BACKGROUND);
        tft.println("ERREUR DOSSIER");

        return;
    }

    if (!root.isDirectory())
    {
        Serial.println("ERREUR : / n'est pas un dossier");

        root.close();
        return;
    }

    File file = root.openNextFile();

    uint16_t count = 0;

    while (file)
    {
        count++;

        Serial.print("  ");
        Serial.print(file.name());

        if (file.isDirectory())
        {
            Serial.println("  <DIR>");
        }
        else
        {
            Serial.print("  ");
            Serial.print(file.size());
            Serial.println(" octets");
        }

        // Affichage TFT
        tft.setTextColor(COLOR_TEXT, COLOR_BACKGROUND);

        if (file.isDirectory())
        {
            tft.print("[DIR] ");
        }

        tft.println(file.name());

        file.close();

        file = root.openNextFile();
    }

    root.close();

    Serial.println("--------------------------------");
    Serial.print("Nombre d'elements : ");
    Serial.println(count);

    tft.setTextColor(COLOR_OK, COLOR_BACKGROUND);
    tft.print("Fichiers : ");
    tft.println(count);
}


// ============================================================
// INITIALISATION SD
// ============================================================

bool initSD()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("INITIALISATION CARTE SD");
    Serial.println("================================");

    Serial.print("SD CS = GPIO");
    Serial.println(SD_CS_PIN);

    tft.setTextColor(COLOR_INFO, COLOR_BACKGROUND);
    tft.println("INITIALISATION SD");
    tft.print("CS GPIO");
    tft.println(SD_CS_PIN);

    // Désactivation du TFT pendant l'initialisation SD
    // afin d'eviter qu'il parle en meme temps sur le bus SPI.
    pinMode(TFT_CS, OUTPUT);
    digitalWrite(TFT_CS, HIGH);

    // CS SD
    pinMode(SD_CS_PIN, OUTPUT);
    digitalWrite(SD_CS_PIN, HIGH);

    delay(100);

    Serial.println("Appel de SD.begin()...");

    if (!SD.begin(SD_CS_PIN))
    {
        Serial.println();
        Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        Serial.println("ERREUR : SD.begin() ECHEC");
        Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

        tft.setTextColor(COLOR_ERROR, COLOR_BACKGROUND);
        tft.println("SD INIT ERROR");

        return false;
    }

    Serial.println();
    Serial.println("SD.begin() = OK");

    tft.setTextColor(COLOR_OK, COLOR_BACKGROUND);
    tft.println("SD INIT OK");

    return true;
}


// ============================================================
// SETUP
// ============================================================

void setup()
{
    Serial.begin(115200);

    delay(1000);

    // --------------------------------------------------------
    // TFT
    // --------------------------------------------------------

    tft.init();

    tft.setRotation(TFT_ROTATION);

    tft.fillScreen(COLOR_BACKGROUND);

    tft.setTextSize(1);

    tft.setCursor(5, 5);

    tft.setTextColor(COLOR_INFO, COLOR_BACKGROUND);

    tft.println("3x0c3t SD TEST");
    tft.println("================");

    // --------------------------------------------------------
    // INFORMATIONS SERIE
    // --------------------------------------------------------

    Serial.println();
    Serial.println();
    Serial.println("========================================");
    Serial.println("       3x0c3t SD CARD TEST");
    Serial.println("========================================");

    Serial.println("ESP8266");
    Serial.println("TFT_eSPI");
    Serial.println("SD.h");
    Serial.println();

    // --------------------------------------------------------
    // INITIALISATION SD
    // --------------------------------------------------------

    bool sdOK = initSD();

    if (!sdOK)
    {
        Serial.println();
        Serial.println("TEST ARRETE.");
        Serial.println("Verifier :");
        Serial.println(" - carte SD inseree");
        Serial.println(" - cablage");
        Serial.println(" - CS SD");
        Serial.println(" - alimentation 3.3V");
        Serial.println(" - MOSI / MISO / SCK");

        tft.println();
        tft.setTextColor(COLOR_ERROR, COLOR_BACKGROUND);
        tft.println("SD ABSENTE");
        tft.println();
        tft.println("TEST ARRETE");

        return;
    }

    // --------------------------------------------------------
    // LISTE FICHIERS
    // --------------------------------------------------------

    listFiles();

    // --------------------------------------------------------
    // ECRITURE
    // --------------------------------------------------------

    bool writeOK = testWrite();

    delay(500);

    // --------------------------------------------------------
    // LECTURE
    // --------------------------------------------------------

    bool readOK = false;

    if (writeOK)
    {
        readOK = testRead();
    }

    // --------------------------------------------------------
    // RESULTAT FINAL
    // --------------------------------------------------------

    Serial.println();
    Serial.println("========================================");
    Serial.println("RESULTAT FINAL");
    Serial.println("========================================");

    if (sdOK && writeOK && readOK)
    {
        Serial.println("SD : OK");
        Serial.println("ECRITURE : OK");
        Serial.println("LECTURE : OK");
        Serial.println();
        Serial.println("CARTE SD FONCTIONNELLE");
    }
    else
    {
        Serial.println("ECHEC DU TEST");
    }

    Serial.println("========================================");

    tft.println();
    tft.println("================");

    if (sdOK && writeOK && readOK)
    {
        tft.setTextColor(COLOR_OK, COLOR_BACKGROUND);
        tft.println("SD : OK");
        tft.println("WRITE : OK");
        tft.println("READ : OK");
        tft.println();
        tft.println("SD FONCTIONNELLE");
    }
    else
    {
        tft.setTextColor(COLOR_ERROR, COLOR_BACKGROUND);
        tft.println("TEST ECHEC");
    }
}


// ============================================================
// LOOP
// ============================================================

void loop()
{
    // Aucun traitement.
    // Le test est effectue une seule fois au demarrage.

    delay(1000);
}