/**
 * @file main.cpp
 * @brief Read temperature and humidity from a DHT11 sensor and display it on an SSD1306 OLED.
 *
 * This sketch initializes a DHT11 sensor and an I2C SSD1306 OLED (128x64) and continuously
 * reads temperature and humidity values. Readings are printed to Serial (for debugging) and
 * rendered on the OLED screen. If the OLED is not found during initialization the sketch
 * halts in setup().
 *
 * Hardware connections (typical):
 * - DHT11 data pin to Arduino digital pin defined by DHTPIN (2)
 * - SSD1306 I2C -> board I2C pins (SDA, SCL)
 *
 * @author Your Name
 * @date 2026-02-11
 * @copyright MIT License (adjust as needed)
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

/** @brief OLED display width in pixels. */
#define SCREEN_WIDTH 128

/** @brief OLED display height in pixels. */
#define SCREEN_HEIGHT 64

/** @brief I2C address of the OLED display. Common values: 0x3C or 0x3D. */
#define OLED_ADDR 0x3C

/** @brief Digital pin connected to the DHT11 data line. */
#define DHTPIN 2

/** @brief DHT sensor model used in this project. */
#define DHTTYPE DHT11

/**
 * @brief Global SSD1306 display instance.
 *
 * The Adafruit_SSD1306 constructor takes (width, height, TwoWire*, resetPin). A reset pin
 * of -1 indicates the library should not toggle a reset line.
 */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

/**
 * @brief Global DHT sensor instance.
 *
 * Constructed with the data pin and sensor type (DHT11).
 */
DHT dht(DHTPIN, DHTTYPE);

/**
 * @brief Arduino setup hook.
 *
 * Initializes Serial for debugging, starts the DHT sensor library, and initializes the
 * SSD1306 OLED display over I2C. If the OLED cannot be initialized the function
 * prints an error message and enters an infinite loop to halt further execution.
 *
 * @note This function is executed once after the board powers up or resets.
 */
void setup() {

    Serial.begin(9600);
    dht.begin();

    if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("OLED NOT FOUND");
        while(true);
    }

    display.clearDisplay();
    display.display();
}

/**
 * @brief Main program loop.
 *
 * Reads temperature (Celsius) and relative humidity from the DHT11 sensor. If a
 * reading fails (NaN) the error is printed to Serial and the current iteration exits.
 * Valid readings are displayed on the OLED using a simple text layout and are also
 * available via the Serial monitor for debugging.
 *
 * Display layout (approximate positions):
 * - Line 1 (y=0): "Temp:" label and numeric temperature in Celsius
 * - Line 2 (y=20): temperature value and unit "C"
 * - Line 3 (y=40): "Hum:" label and numeric humidity with "%"
 *
 * The loop updates every 2 seconds.
 */
void loop() {

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT!");
        return;
    }

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0, 0);
    display.print("Temp:");
    display.setCursor(0, 20);
    display.print(temperature);
    display.print(" C");

    display.setCursor(0, 40);
    display.print("Hum:");
    display.print(humidity);
    display.print(" %");
    display.display();

    delay(2000); // Update every 2 seconds
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