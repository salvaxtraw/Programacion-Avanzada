#include <Arduino.h>

// --- Constants & Pin Definitions ---
const int POT_PIN = 34;   // GPIO34 (ADC1_CH6)
const int LED_PIN = 4;    // GPIO4
const int THRESHOLD = 2048; // Halfway point (0-4095 for ESP32 ADC)

// --- Variables for Filtering ---
const int NUM_READINGS = 10;
int readings[NUM_READINGS];
int readIndex = 0;
long total = 0;
int averagePotValue = 0;

// --- Function Prototypes ---
void readAndSmoothSensor();
void updateLEDLogic();

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);

    analogReadResolution(12); // 12 bits → 0–4095

    for (int i = 0; i < NUM_READINGS; i++) {
        readings[i] = 0;
    }

    Serial.println("\n--- Program Initialized (ESP32) ---");
}

void loop() {
    readAndSmoothSensor();
    updateLEDLogic();
    delay(100);
}

// --- Function Definitions ---

void readAndSmoothSensor() {

    total = total - readings[readIndex];

    // Si el potenciómetro está invertido usa esta línea
    readings[readIndex] = 4095 - analogRead(POT_PIN);

    // Si está normal usa esta
    // readings[readIndex] = analogRead(POT_PIN);

    total = total + readings[readIndex];

    readIndex = readIndex + 1;

    if (readIndex >= NUM_READINGS) {
        readIndex = 0;
    }

    averagePotValue = total / NUM_READINGS;
}

void updateLEDLogic() {

    if (averagePotValue > THRESHOLD) {
        digitalWrite(LED_PIN, HIGH);
    } 
    else {
        digitalWrite(LED_PIN, LOW);
    }

    Serial.print("Smoothed Value: ");
    Serial.print(averagePotValue);
    Serial.print(" | LED: ");

    if (averagePotValue > THRESHOLD) {
        Serial.println("ON");
    } else {
        Serial.println("OFF");
    }
}