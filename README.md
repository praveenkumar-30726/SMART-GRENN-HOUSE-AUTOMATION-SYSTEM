# SMART-GRENN-HOUSE-AUTOMATION-SYSTEM
Smart Greenhouse Automation System using Arduino UNO that monitors temperature, humidity, soil moisture, water level, rainfall, and light intensity. Features automatic irrigation, OLED display, buzzer alerts, LED indicators, and real-time serial monitoring for efficient greenhouse management.
# 🌱 Smart Greenhouse Automation System

## Overview

The **Smart Greenhouse Automation System** is an Arduino-based embedded project designed to monitor and automate essential greenhouse environmental conditions. The system continuously measures **temperature, humidity, soil moisture, water level, rainfall, and light intensity** to help maintain optimal plant growth.

Using multiple sensors, the system automatically controls a **water pump** for irrigation, displays live sensor readings on an **OLED display**, activates **LED indicators** for different environmental conditions, and triggers a **buzzer alert** whenever abnormal values are detected.

## Features

* 🌡️ Temperature monitoring (DHT11)
* 💧 Humidity monitoring
* 🌱 Soil moisture sensing
* 🚰 Water level monitoring
* 🌧️ Rain detection
* ☀️ Light intensity monitoring (LDR)
* 💦 Automatic water pump control using relay
* 📺 Real-time OLED display
* 🚨 Buzzer alert system
* 💡 LED status indicators
* 📊 Serial Monitor output for data logging

## Hardware Used

* Arduino Uno
* DHT11 Temperature & Humidity Sensor
* Soil Moisture Sensor
* Water Level Sensor
* Rain Sensor
* LDR (Light Dependent Resistor)
* 0.96" OLED Display (SSD1306)
* Relay Module
* Water Pump
* Buzzer
* LEDs
* Jumper Wires
* Breadboard

## Software

* Arduino IDE
* C/C++
* Adafruit SSD1306 Library
* Adafruit GFX Library
* DHT Sensor Library

## Working

The system continuously reads data from all sensors and displays the values on the OLED screen. Based on predefined threshold values, it:

* Automatically turns the water pump ON/OFF.
* Activates LED indicators for different environmental conditions.
* Sounds a buzzer when abnormal conditions are detected.
* Sends sensor readings to the Serial Monitor for real-time monitoring.

## Applications

* Smart Agriculture
* Greenhouse Automation
* Precision Farming
* Plant Monitoring Systems
* Educational Embedded Systems Projects

## Author

**Praveen Kumar N**

⭐ If you found this project useful, consider giving this repository a star!

