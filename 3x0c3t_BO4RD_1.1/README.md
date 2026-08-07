# 3x0c3t_BO4RD v1.1

Interface graphique TFT SPI basée sur ESP8266 avec écran couleur **240x320**.

Cette version ajoute une évolution majeure par rapport à la première version :

* gestion météo via OpenWeather,
* architecture modulaire,
* séparation des fonctions par fichiers `.cpp/.h`,
* préparation pour plusieurs pages d'affichage.

---

## 📌 Fonctionnalités

### Écran TFT SPI

* Résolution : 240x320
* Gestion affichage graphique
* Logo RGB565 intégré
* Écrans de démarrage (Splash Screen)
* Gestion des pages d'affichage

### Horloge

* Affichage de l'heure
* Module dédié :

  * `heure.cpp`
  * `heure.h`

### Météo OpenWeather

Module :

```
meteo.cpp
meteo.h
```

Informations prévues :

* Température actuelle
* Température ressentie
* Température minimale / maximale
* Humidité
* Pression
* Vent
* Conditions météo
* Prévisions

---

## 📂 Organisation du projet

```
3x0c3t_BO4RD_1.1
│
├── 3x0c3t_BO4RD_1.1.ino   # Programme principal
│
├── config.h               # Configuration générale
│
├── display.cpp/h          # Gestion écran TFT
│
├── screens.cpp/h          # Gestion des pages écran
│
├── meteo.cpp/h            # Gestion météo OpenWeather
│
├── heure.cpp/h            # Gestion horloge
│
├── wifi_manager.cpp/h     # Connexion WiFi
│
├── splash.cpp/h           # Écran de démarrage
│
├── progress.cpp/h         # Barre de progression
│
├── logo.cpp/h             # Logo converti RGB565
│
└── assets/
    └── logo_rgb565.txt
```

---

## 🔧 Matériel utilisé

### ESP8266

Carte compatible :

* NodeMCU ESP8266
* Wemos D1 Mini

### Écran TFT SPI

Compatible :

* ILI9341
* autres contrôleurs SPI compatibles selon configuration

---

## 📚 Bibliothèques Arduino nécessaires

* TFT_eSPI
* ESP8266WiFi
* ESP8266HTTPClient
* ArduinoJson
* NTPClient
* TimeLib

---

## 🌐 Configuration OpenWeather

Créer une clé API :

https://openweathermap.org/api

Configurer ensuite les paramètres dans :

```
config.h
```

Exemple :

```cpp
#define WIFI_SSID "Votre_Wifi"
#define WIFI_PASSWORD "Votre_Mot_De_Passe"

#define WEATHER_API_KEY "Votre_Cle_API"
```

---

## 🚀 Versions

### v1.0

Version initiale :

* affichage TFT,
* logo,
* horloge,
* structure modulaire.

### v1.1

Ajouts :

* module météo OpenWeather,
* nouvelles ressources graphiques,
* préparation pages météo avancées.

---

## 🛠️ Évolutions prévues

* Pages météo complètes :

  * Page 1 : températures et conditions actuelles
  * Page 2 : prévisions détaillées
* Icônes météo graphiques
* Gestion tactile
* Capteurs locaux ESP8266
* Synchronisation avec Raspberry Pi

---

## Auteur

Projet développé par **3x0c3t**

GitHub :
https://github.com/3x0c3t

Projet expérimental ESP8266 / TFT SPI / IoT.
