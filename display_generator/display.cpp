#include "display.h"


// ============================================================
// OBJET TFT
// ============================================================

TFT_eSPI tft = TFT_eSPI();


// ============================================================
// INITIALISATION TFT
// ============================================================

void displayInit()
{
    Serial.println();
    Serial.println("Initialisation TFT...");

    tft.init();
    tft.setRotation(TFT_ROTATION);
    tft.fillScreen(COLOR_BACKGROUND);

    Serial.println("TFT OK");
}


// ============================================================
// INITIALISATION SD
// ============================================================

bool sdInit()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("INITIALISATION SD");
    Serial.println("================================");

    Serial.print("SD CS = GPIO ");
    Serial.println(SD_CS);

    if (!SD.begin(SD_CS))
    {
        Serial.println("ERREUR : SD.begin() a echoue");
        return false;
    }

    Serial.println("SD OK");

    // --------------------------------------------------------
    // Test simple de lecture
    // --------------------------------------------------------

    if (SD.exists("/"))
    {
        Serial.println("Racine SD accessible");
    }
    else
    {
        Serial.println("ATTENTION : racine SD inaccessible");
    }

    return true;
}


// ============================================================
// LISTE DES FICHIERS SD
// ============================================================

void listSDFiles()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("FICHIERS SD");
    Serial.println("================================");

    fs::File root = SD.open("/");

    if (!root)
    {
        Serial.println("ERREUR : impossible d'ouvrir /");
        return;
    }

    if (!root.isDirectory())
    {
        Serial.println("ERREUR : / n'est pas un dossier");

        root.close();

        return;
    }

    uint8_t count = 0;

    fs::File file = root.openNextFile();

    while (file)
    {
        count++;

        Serial.print("  ");
        Serial.print(file.name());

        if (file.isDirectory())
        {
            Serial.println(" [DOSSIER]");
        }
        else
        {
            Serial.print(" : ");
            Serial.print(file.size());
            Serial.println(" octets");
        }

        file.close();

        file = root.openNextFile();
    }

    root.close();

    Serial.print("Nombre d'elements : ");
    Serial.println(count);

    if (count == 0)
    {
        Serial.println("AUCUN FICHIER SUR LA SD");
    }
}


// ============================================================
// VERIFICATION DES PAGES
// ============================================================

bool checkSDPages()
{
    Serial.println();
    Serial.println("================================");
    Serial.println("VERIFICATION DES PAGES");
    Serial.println("================================");

    bool allOK = true;

    for (uint8_t page = 1; page <= PAGE_COUNT; page++)
    {
        char filename[32];

        snprintf(
            filename,
            sizeof(filename),
            "/page%u.json",
            page
        );

        Serial.print("  ");
        Serial.print(filename);
        Serial.print(" : ");

        if (SD.exists(filename))
        {
            Serial.println("OK");
        }
        else
        {
            Serial.println("ABSENT");

            allOK = false;
        }
    }

    Serial.println();

    if (allOK)
    {
        Serial.println("Toutes les pages sont presentes");
    }
    else
    {
        Serial.println("ATTENTION : une ou plusieurs pages manquent");
    }

    return allOK;
}


// ============================================================
// COULEURS
// ============================================================

uint16_t getColor(const char *color)
{
    if (!color)
        return TFT_WHITE;


    if (!strcmp(color, "TFT_BLACK") ||
        !strcmp(color, "ILI9341_BLACK"))
        return TFT_BLACK;


    if (!strcmp(color, "TFT_WHITE") ||
        !strcmp(color, "ILI9341_WHITE"))
        return TFT_WHITE;


    if (!strcmp(color, "TFT_RED") ||
        !strcmp(color, "ILI9341_RED"))
        return TFT_RED;


    if (!strcmp(color, "TFT_GREEN") ||
        !strcmp(color, "ILI9341_GREEN"))
        return TFT_GREEN;


    if (!strcmp(color, "TFT_BLUE") ||
        !strcmp(color, "ILI9341_BLUE"))
        return TFT_BLUE;


    if (!strcmp(color, "TFT_CYAN") ||
        !strcmp(color, "ILI9341_CYAN"))
        return TFT_CYAN;


    if (!strcmp(color, "TFT_MAGENTA") ||
        !strcmp(color, "ILI9341_MAGENTA"))
        return TFT_MAGENTA;


    if (!strcmp(color, "TFT_YELLOW") ||
        !strcmp(color, "ILI9341_YELLOW"))
        return TFT_YELLOW;


    if (!strcmp(color, "TFT_ORANGE") ||
        !strcmp(color, "ILI9341_ORANGE"))
        return TFT_ORANGE;


    if (!strcmp(color, "TFT_PINK") ||
        !strcmp(color, "ILI9341_PINK"))
        return TFT_PINK;


    if (!strcmp(color, "TFT_DARKGREY") ||
        !strcmp(color, "ILI9341_DARKGREY"))
        return TFT_DARKGREY;


    if (!strcmp(color, "TFT_LIGHTGREY") ||
        !strcmp(color, "ILI9341_LIGHTGREY"))
        return TFT_LIGHTGREY;


    if (!strcmp(color, "TFT_BROWN") ||
        !strcmp(color, "ILI9341_BROWN"))
        return TFT_BROWN;


    return TFT_WHITE;
}


// ============================================================
// CHARGEMENT JSON
// ============================================================

bool loadJSONFile(const char *filename)
{
    Serial.println();
    Serial.println("================================");

    Serial.print("Chargement SD : ");
    Serial.println(filename);


    // --------------------------------------------------------
    // EXISTENCE
    // --------------------------------------------------------

    if (!SD.exists(filename))
    {
        Serial.print("ERREUR : fichier absent : ");
        Serial.println(filename);

        return false;
    }


    // --------------------------------------------------------
    // OUVERTURE
    // --------------------------------------------------------

    fs::File file = SD.open(
        filename,
        FILE_READ
    );


    if (!file)
    {
        Serial.print("ERREUR : impossible d'ouvrir : ");
        Serial.println(filename);

        return false;
    }


    // --------------------------------------------------------
    // TAILLE
    // --------------------------------------------------------

    size_t fileSize = file.size();

    Serial.print("Taille JSON : ");
    Serial.print(fileSize);
    Serial.println(" octets");


    // --------------------------------------------------------
    // PROTECTION MEMOIRE
    // --------------------------------------------------------

    if (fileSize > 16000)
    {
        Serial.println(
            "ERREUR : JSON trop volumineux"
        );

        file.close();

        return false;
    }


    // --------------------------------------------------------
    // PARSING JSON
    // --------------------------------------------------------

    DynamicJsonDocument doc(8192);

    DeserializationError error =
        deserializeJson(
            doc,
            file
        );


    file.close();


    // --------------------------------------------------------
    // ERREUR JSON
    // --------------------------------------------------------

    if (error)
    {
        Serial.print("ERREUR JSON : ");
        Serial.println(error.c_str());

        return false;
    }


    Serial.println("JSON valide");


    // --------------------------------------------------------
    // AFFICHAGE
    // --------------------------------------------------------

    drawJSONPage(doc);


    Serial.print("Page affichee : ");
    Serial.println(filename);


    return true;
}


// ============================================================
// CHARGEMENT PAGE
// ============================================================

bool loadJSONPage(uint8_t page)
{
    char filename[32];

    snprintf(
        filename,
        sizeof(filename),
        "/page%u.json",
        page
    );

    Serial.print("Chargement : ");
    Serial.println(filename);

    return loadJSONFile(filename);
}


// ============================================================
// AFFICHAGE PAGE JSON
// ============================================================

void drawJSONPage(JsonDocument &doc)
{
    tft.fillScreen(
        COLOR_BACKGROUND
    );


    JsonArray objects =
        doc["objects"].as<JsonArray>();


    if (objects.isNull())
    {
        Serial.println(
            "ERREUR : tableau 'objects' absent"
        );

        return;
    }


    Serial.print("Nombre d'objets : ");
    Serial.println(objects.size());


    for (JsonObject object : objects)
    {
        if (object["visible"] == false)
            continue;

        drawJSONObject(object);
    }
}


// ============================================================
// OBJET JSON
// ============================================================

void drawJSONObject(JsonObject object)
{
    const char *type =
        object["type"];


    if (!type)
        return;


    if (!strcmp(type, "text"))
    {
        drawJSONText(object);
    }


    else if (!strcmp(type, "shape"))
    {
        drawJSONShape(object);
    }


    else if (!strcmp(type, "line"))
    {
        drawJSONLine(object);
    }


    else
    {
        Serial.print("Type inconnu : ");
        Serial.println(type);
    }
}


// ============================================================
// TEXTE
// ============================================================

void drawJSONText(JsonObject object)
{
    int x =
        object["x"] | 0;

    int y =
        object["y"] | 0;

    int size =
        object["size"] | 1;

    const char *text =
        object["text"] | "";


    const char *colorName =
        object["color"] | "TFT_WHITE";


    uint16_t color =
        getColor(colorName);


    tft.setTextColor(
        color,
        COLOR_BACKGROUND
    );


    tft.setTextSize(
        size
    );


    tft.setCursor(
        x,
        y
    );


    tft.print(
        text
    );
}


// ============================================================
// FORMES
// ============================================================

void drawJSONShape(JsonObject object)
{
    const char *shape =
        object["shape"] | "rect";


    const char *colorName =
        object["color"] | "TFT_WHITE";


    int x =
        object["x"] | 0;

    int y =
        object["y"] | 0;

    int width =
        object["width"] | 0;

    int height =
        object["height"] | 0;

    int radius =
        object["radius"] | 0;


    uint16_t color =
        getColor(colorName);


    // --------------------------------------------------------
    // CERCLE
    // --------------------------------------------------------

    if (!strcmp(shape, "circle"))
    {
        int r =
            object["radius"] | 10;


        tft.drawCircle(
            x,
            y,
            r,
            color
        );
    }


    // --------------------------------------------------------
    // CARRE
    // --------------------------------------------------------

    else if (!strcmp(shape, "square"))
    {
        int size =
            width;


        if (size <= 0)
            size = height;


        if (size <= 0)
            size = 20;


        tft.drawRect(
            x,
            y,
            size,
            size,
            color
        );
    }


    // --------------------------------------------------------
    // RECTANGLE ARRONDI
    // --------------------------------------------------------

    else if (!strcmp(shape, "roundRect"))
    {
        if (radius <= 0)
            radius = 5;


        tft.drawRoundRect(
            x,
            y,
            width,
            height,
            radius,
            color
        );
    }


    // --------------------------------------------------------
    // RECTANGLE
    // --------------------------------------------------------

    else
    {
        tft.drawRect(
            x,
            y,
            width,
            height,
            color
        );
    }
}


// ============================================================
// LIGNE
// ============================================================

void drawJSONLine(JsonObject object)
{
    int x1 =
        object["x1"] | 0;

    int y1 =
        object["y1"] | 0;

    int x2 =
        object["x2"] | 0;

    int y2 =
        object["y2"] | 0;


    const char *colorName =
        object["color"] | "TFT_WHITE";


    uint16_t color =
        getColor(colorName);


    tft.drawLine(
        x1,
        y1,
        x2,
        y2,
        color
    );
}


// ============================================================
// PAGE
// ============================================================

void drawPage(uint8_t page)
{
    if (!loadJSONPage(page))
    {
        tft.fillScreen(
            TFT_BLACK
        );


        tft.setTextColor(
            TFT_RED,
            TFT_BLACK
        );


        tft.setTextSize(2);


        tft.setCursor(
            10,
            20
        );


        tft.print(
            "JSON ERROR"
        );


        tft.setCursor(
            10,
            50
        );


        tft.print(
            "PAGE "
        );


        tft.print(
            page
        );
    }
}