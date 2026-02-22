#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Light Intensity Monitoring using LDR
 * @author bharti
 * @date 2026-02-22
 *
 * @details
 * Reads analog brightness data from LDR sensor
 * and displays structured output via Serial Monitor.
 */

// TODO 1:
// Define LDR analog pin (Use A0)
#define LDR_PIN A0

// TODO 2:
// Create variable to store sensor reading
int ldrValue = 0;

void setup() {

    // TODO 3:
    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // TODO 4:
    // Print system initialization message
    Serial.println("LDR Light Intensity Monitoring System");
    Serial.println("Author: bharti");
    Serial.println("System Initialized...");
}

void loop() {

    // TODO 5:
    // Read analog value from LDR
    ldrValue = analogRead(LDR_PIN);

    // Convert ADC value (0-1023) to percentage
    int lightPercent = map(ldrValue, 0, 1023, 0, 100);
    Serial.print("Light Intensity: ");
    Serial.print(lightPercent);
    Serial.println(" %");

    // TODO 6:
    // Print raw ADC value
    Serial.print("Raw ADC Value: ");
    Serial.println(ldrValue);

    // TODO 7:
    // Apply threshold logic (Bright / Dark detection)
    if (ldrValue > 500) {  // Adjust threshold as needed
        // TODO 8:
        // Print brightness status
        Serial.println("Bright Light Detected");
    } else {
        Serial.println("Dark Detected");
    }

    // TODO 9:
    // Add delay (500ms or 1 second)
    delay(500);
}