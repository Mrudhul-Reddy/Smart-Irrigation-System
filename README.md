# Smart Irrigation System

## Overview

This project demonstrates a smart irrigation system using an ESP8266 microcontroller, a soil moisture sensor, a relay module, and an LCD display. The system monitors soil moisture levels and controls a water pump based on the readings. Real-time data is displayed on the LCD and can also be monitored and controlled via the Blynk IoT app.

## Components

- **ESP8266** microcontroller
- **Soil moisture sensor**
- **Relay module**
- **Water pump or motor**
- **LCD (I2C) display**
- **Blynk IoT app** (smartphone)

## Libraries

- `Wire` for I2C communication
- `LiquidCrystal_I2C` for the LCD
- `ESP8266WiFi` for Wi-Fi connectivity
- `Blynk` for IoT communication

Setup Instructions

    Install Arduino IDE if not already installed.
    Install ESP8266 board support in Arduino IDE.
    Install required libraries:
        Go to Sketch -> Include Library -> Manage Libraries.
        Search for and install Wire, LiquidCrystal_I2C, and Blynk.
    Connect the hardware:
        Soil Moisture Sensor: Connect the analog output to A0.
        Relay Module: Connect control pin to D1.
        LCD Display: Connect I2C SDA to D2 and SCL to D1 (or adjust as necessary).
    Replace placeholder values in the code:
        Blynk Auth Token: Replace "YOUR_BLYNK_AUTH_TOKEN" with your actual Blynk auth token.
        Wi-Fi Credentials: Replace "YOUR_SSID" and "YOUR_PASSWORD" with your Wi-Fi network credentials.
    Upload the code to your ESP8266.
    Configure the Blynk App:
        Create a new project in Blynk.
        Add a Value Display widget for soil moisture (Virtual Pin V1).
        Add a Button widget for controlling the relay (Virtual Pin V2), set to switch mode (HIGH/LOW).
    Power up the system and monitor/control via the LCD and Blynk app.

Troubleshooting

    Ensure your ESP8266 is properly connected to Wi-Fi.
    Verify that your Blynk Auth Token and Wi-Fi credentials are correctly entered.
    Check all hardware connections and pin assignments.
