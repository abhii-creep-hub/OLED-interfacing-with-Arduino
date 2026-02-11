#include <Arduino.h>
#include <wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR    0X3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void setup() {
    Serial.begin(9600);
    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println(F("OLED NOT FOUND"));
        while (true);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Arduino OLED Test");
    display.println("OLED with I2C");
    display.display();


}

void loop() {
    // write your code here
}
/**
 *@file main.cpp
 *@brief Read temperature and humidity from a DHT11 sensor and display it on an SSD130
 *@author Abhinav Kumar Sharma
 *@version 1.0
 *@date 2026-02-11
 *
 *@details
 * * This sketch initializes a DHT11 sensor and an I2C SSD1306 OLED (128x64) and continuously
 * reads temperature and humidity values. Readings are printed to Serial (for debugging) and
 * rendered on the OLED screen. If the OLED is not found during initialization the sketch
 * halts in setup().
 * * Hardware connections (typical):
 * - DHT11 data pin to Arduino digital pin defined by DHTPIN (2)
 * - SSD1306 I2C -> board I2C pins (SDA, SCL)
 */