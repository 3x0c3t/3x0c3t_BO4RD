#include "meteo.h"

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <time.h>

#include "display.h"
#include "config.h"

float temperature = 0;
float feelsLike = 0;
float tempMin = 0;
float tempMax = 0;

int humidity = 0;
int pressure = 0;

time_t sunriseTime = 0;
time_t sunsetTime = 0;

String sunrise = "--:--";
String sunset = "--:--";
String lastUpdate = "--:--";

String weatherDescription = "--";


static String unixToHour(unsigned long unixTime)
{
    time_t raw = unixTime;
    struct tm *t = localtime(&raw);

    if (t == nullptr)
        return "--:--";

    char buffer[6];

    sprintf(
        buffer,
        "%02d:%02d",
        t->tm_hour,
        t->tm_min
    );

    return String(buffer);
}


void initWeather()
{
    Serial.println("Initialisation METEO");
    updateWeather();
}


void updateWeather()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("WiFi non connecte");
        return;
    }

    WiFiClient client;
    HTTPClient http;

    String url =
        "http://api.openweathermap.org/data/2.5/weather?q=" +
        String(WEATHER_CITY) +
        "," +
        String(WEATHER_COUNTRY) +
        "&units=metric&lang=fr&appid=" +
        String(WEATHER_API_KEY);

    Serial.println("====================");
    Serial.println("REQUETE METEO");
    Serial.println(url);
    Serial.println("====================");

    http.begin(client,url);

    int httpCode = http.GET();

    Serial.print("HTTP CODE : ");
    Serial.println(httpCode);

    if (httpCode == HTTP_CODE_OK)
    {
        String json = http.getString();

        Serial.println("========== JSON ==========");
        Serial.println(json);
        Serial.println("==========================");

        StaticJsonDocument<3072> doc;

        DeserializationError error =
            deserializeJson(doc,json);

        if(error)
        {
            Serial.print("Erreur JSON : ");
            Serial.println(error.c_str());
        }
        else
        {
            Serial.println("JSON OK");

            temperature = doc["main"]["temp"].as<float>();
            feelsLike = doc["main"]["feels_like"].as<float>();

            tempMin = doc["main"]["temp_min"].as<float>();
            tempMax = doc["main"]["temp_max"].as<float>();

            humidity = doc["main"]["humidity"].as<int>();
            pressure = doc["main"]["pressure"].as<int>();

            sunriseTime = doc["sys"]["sunrise"].as<time_t>();
            sunsetTime = doc["sys"]["sunset"].as<time_t>();

            sunrise = unixToHour(sunriseTime);
            sunset = unixToHour(sunsetTime);

            weatherDescription =
                String((const char*)doc["weather"][0]["description"]);

            if(weatherDescription.length() > 18)
            {
                weatherDescription =
                    weatherDescription.substring(0,18);
            }

            lastUpdate = unixToHour(time(nullptr));

            Serial.println("===== METEO =====");

            Serial.print("Temp actuelle : ");
            Serial.println(temperature);

            Serial.print("Temp mini : ");
            Serial.println(tempMin);

            Serial.print("Temp maxi : ");
            Serial.println(tempMax);

            Serial.print("Ressenti : ");
            Serial.println(feelsLike);

            Serial.print("Humidite : ");
            Serial.println(humidity);

            Serial.print("Pression : ");
            Serial.println(pressure);

            Serial.print("Lever : ");
            Serial.println(sunrise);

            Serial.print("Coucher : ");
            Serial.println(sunset);

            Serial.print("Description : ");
            Serial.println(weatherDescription);

            Serial.print("MAJ : ");
            Serial.println(lastUpdate);
        }
    }
    else
    {
        Serial.print("Erreur HTTP : ");
        Serial.println(httpCode);
    }

    http.end();
}


void drawWeather()
{
    tft.setTextDatum(MC_DATUM);

    // MINI MAXI

    tft.setTextColor(TFT_WHITE,TFT_BLACK);

    tft.drawString(
        "MIN",
        55,
        CONTENT_Y + 8,
        2
    );

    tft.drawString(
        "MAX",
        185,
        CONTENT_Y + 8,
        2
    );

    tft.setTextColor(TFT_CYAN,TFT_BLACK);

    tft.drawString(
        String(tempMin,1)+" C",
        55,
        CONTENT_Y + 30,
        3
    );

    tft.drawString(
        String(tempMax,1)+" C",
        185,
        CONTENT_Y + 30,
        3
    );

    // TEMPERATURE ACTUELLE

    uint16_t color = TFT_CYAN;

    if(temperature >= 30)
        color = TFT_RED;
    else if(temperature >=20)
        color = TFT_ORANGE;
    else if(temperature >=10)
        color = TFT_GREEN;

    tft.setTextColor(color,TFT_BLACK);

    tft.drawString(
        String(temperature,1)+" C",
        SCREEN_WIDTH/2,
        CONTENT_Y + 68,
        6
    );

    // RESSENTI

    tft.setTextColor(TFT_YELLOW,TFT_BLACK);

    tft.drawString(
        "Ressenti "+String(feelsLike,1)+" C",
        SCREEN_WIDTH/2,
        CONTENT_Y + 105,
        2
    );

    // DESCRIPTION

    tft.setTextColor(TFT_WHITE,TFT_BLACK);

    tft.drawString(
        weatherDescription,
        SCREEN_WIDTH/2,
        CONTENT_Y + 128,
        2
    );

    // HUMIDITE

    tft.drawRoundRect(
        10,
        CONTENT_Y + 150,
        105,
        45,
        5,
        TFT_DARKGREY
    );

    tft.drawString(
        "Hum.",
        62,
        CONTENT_Y + 160,
        2
    );

    tft.setTextColor(TFT_CYAN,TFT_BLACK);

    tft.drawString(
        String(humidity)+"%",
        62,
        CONTENT_Y + 180,
        3
    );

    // PRESSION

    tft.setTextColor(TFT_WHITE,TFT_BLACK);

    tft.drawRoundRect(
        125,
        CONTENT_Y + 150,
        105,
        45,
        5,
        TFT_DARKGREY
    );

    tft.drawString(
        "Press.",
        177,
        CONTENT_Y + 160,
        2
    );

    tft.setTextColor(TFT_GREEN,TFT_BLACK);

    tft.drawString(
        String(pressure),
        177,
        CONTENT_Y + 180,
        3
    );

    // SOLEIL

    tft.setTextColor(TFT_WHITE,TFT_BLACK);

    tft.drawFastHLine(
        10,
        CONTENT_Y + 210,
        220,
        TFT_DARKGREY
    );

    tft.drawString(
        "Lever "+sunrise,
        65,
        CONTENT_Y + 230,
        2
    );

    tft.drawString(
        "Coucher "+sunset,
        175,
        CONTENT_Y + 230,
        2
    );

    // MAJ

    tft.setTextColor(TFT_LIGHTGREY,TFT_BLACK);

    tft.drawString(
        "MAJ "+lastUpdate,
        SCREEN_WIDTH/2,
        CONTENT_Y + 250,
        2
    );
}