#include "ui.h"

#include <TFT_eSPI.h>

#include "display.h"
#include "screens.h"

// =====================================================
// CONFIGURATION UI
// =====================================================

#define HEADER_Y        5
#define HEADER_HEIGHT   20

#define HEADER_LINE_Y   \
    (HEADER_Y + HEADER_HEIGHT)

// =====================================================
// FOOTER
// =====================================================

#define FOOTER_HEIGHT 35
#define FOOTER_Y       \
    (SCREEN_HEIGHT - FOOTER_HEIGHT)

// =====================================================
// BOUTONS FOOTER
// =====================================================

#define FOOTER_BUTTON_GAP 3

// =====================================================
// COULEURS
// =====================================================

#define UI_BACKGROUND TFT_BLACK
#define UI_TEXT       TFT_WHITE
#define UI_PRIMARY    TFT_CYAN
#define UI_BUTTON     TFT_CYAN

// =====================================================
// INITIALISATION
// =====================================================

void uiInit()
{
    Serial.println(
        "UI : initialisation"
    );
}

// =====================================================
// TEST ZONE
// =====================================================

bool uiPointInside(
    int16_t x,
    int16_t y,
    const TouchZone &zone
)
{
    return (
        x >= zone.x &&
        x < zone.x + zone.width &&
        y >= zone.y &&
        y < zone.y + zone.height
    );
}

// =====================================================
// HEADER
// =====================================================

void drawHeader()
{
    // -------------------------------------------------
    // Fond
    // -------------------------------------------------

    tft.fillRect(
        0,
        HEADER_Y,
        SCREEN_WIDTH,
        HEADER_HEIGHT,
        UI_BACKGROUND
    );

    // -------------------------------------------------
    // Ligne
    // -------------------------------------------------

    tft.drawLine(
        0,
        HEADER_LINE_Y,
        SCREEN_WIDTH - 1,
        HEADER_LINE_Y,
        UI_PRIMARY
    );

    // -------------------------------------------------
    // Heure
    // -------------------------------------------------

    tft.setTextColor(
        UI_TEXT,
        UI_BACKGROUND
    );

    tft.setTextSize(1);

    tft.setCursor(
        5,
        HEADER_Y + 6
    );

    tft.print(
        "--:--:--"
    );

    // -------------------------------------------------
    // Date
    // -------------------------------------------------

    tft.setCursor(
        65,
        HEADER_Y + 6
    );

    tft.print(
        "--/--/----"
    );

    // -------------------------------------------------
    // 4 indicateurs
    // -------------------------------------------------

    int boxSize = 14;
    int gap = 3;

    int totalWidth =
        4 * boxSize +
        3 * gap;

    int startX =
        SCREEN_WIDTH -
        totalWidth -
        5;

    int y =
        HEADER_Y +
        (HEADER_HEIGHT - boxSize) / 2;

    for (int i = 0; i < 4; i++)
    {
        int x =
            startX +
            i * (boxSize + gap);

        tft.drawRect(
            x,
            y,
            boxSize,
            boxSize,
            UI_PRIMARY
        );
    }
}

// =====================================================
// FOOTER
// =====================================================

void drawFooter()
{
    tft.fillRect(
        0,
        FOOTER_Y,
        SCREEN_WIDTH,
        FOOTER_HEIGHT,
        UI_BACKGROUND
    );

    int buttonWidth =
        (
            SCREEN_WIDTH -
            5 -
            3 * FOOTER_BUTTON_GAP
        ) / 4;

    for (int i = 0; i < 4; i++)
    {
        int x =
            2 +
            i * (
                buttonWidth +
                FOOTER_BUTTON_GAP
            );

        tft.drawRect(
            x,
            FOOTER_Y + 5,
            buttonWidth,
            FOOTER_HEIGHT - 10,
            UI_PRIMARY
        );

        tft.setTextColor(
            UI_TEXT,
            UI_BACKGROUND
        );

        tft.setTextSize(1);

        tft.setCursor(
            x + 10,
            FOOTER_Y + 16
        );

        switch (i)
        {
            case 0:
                tft.print("HOME");
                break;

            case 1:
                tft.print("METEO");
                break;

            case 2:
                tft.print("SYSTEM");
                break;

            case 3:
                tft.print("WIFI");
                break;
        }
    }
}

// =====================================================
// GESTION TOUCH UI
// =====================================================

void uiHandleTouch(
    int16_t x,
    int16_t y
)
{
    Serial.print(
        "UI TOUCH X="
    );

    Serial.print(x);

    Serial.print(
        " Y="
    );

    Serial.println(y);

    // -------------------------------------------------
    // FOOTER
    // -------------------------------------------------

    if (y >= FOOTER_Y)
    {
        int buttonWidth =
            (
                SCREEN_WIDTH -
                5 -
                3 * FOOTER_BUTTON_GAP
            ) / 4;

        for (int i = 0; i < 4; i++)
        {
            int bx =
                2 +
                i * (
                    buttonWidth +
                    FOOTER_BUTTON_GAP
                );

            TouchZone zone;

            zone.x = bx;
            zone.y = FOOTER_Y + 5;
            zone.width = buttonWidth;
            zone.height = FOOTER_HEIGHT - 10;

            if (
                uiPointInside(
                    x,
                    y,
                    zone
                )
            )
            {
                Serial.print(
                    "FOOTER BUTTON : "
                );

                Serial.println(i);

                switch (i)
                {
                    case 0:
                        screensShow(
                            SCREEN_HOME
                        );
                        break;

                    case 1:
                        screensShow(
                            SCREEN_METEO
                        );
                        break;

                    case 2:
                        screensShow(
                            SCREEN_SYSTEM
                        );
                        break;

                    case 3:
                        screensShow(
                            SCREEN_WIFI
                        );
                        break;
                }

                return;
            }
        }
    }
}