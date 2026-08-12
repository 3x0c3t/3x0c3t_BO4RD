# 3x0c3t BO4RD v3.1

Projet ESP8266 avec écran TFT ILI9341.

## Matériel

- ESP8266 NodeMCU
- TFT SPI ILI9341
- Résolution 240x320
- Affichage paysage 320x240

## Brochage

| Fonction | ESP8266 |
|---|---|
| TFT CS | D8 / GPIO15 |
| TFT DC | D4 / GPIO2 |
| TFT RST | D0 / GPIO16 |
| TFT SCK | D5 / GPIO14 |
| TFT MISO | D6 / GPIO12 |
| TFT MOSI | D7 / GPIO13 |

## Bibliothèques

- Adafruit GFX Library
- Adafruit ILI9341

## Version

v3.1

Base minimale :
ESP8266 + ILI9341 + menu.

Le tactile XPT2046 sera ajouté dans une étape suivante.