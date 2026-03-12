#include "potenciometro.h"
#include <Arduino.h>

// Aquí es donde realmente se crean las variables
const int POT_PIN = 26; // GP26 en la Pico (ADC0)
const int NUM_READINGS = 10;
int readings[NUM_READINGS];
int readIndex = 0;
long total = 0;
int averagePotValue = 0;

void medicion() {
    analogReadResolution(12); // La Pico también soporta 12 bits
    for (int i = 0; i < NUM_READINGS; i++) {
        readings[i] = 0;
    }
}

void lectura() {
total = total - readings[readIndex];
readings[readIndex] = 4095 - analogRead(POT_PIN);
total = total + readings[readIndex];
readIndex = readIndex + 1;
if (readIndex >= NUM_READINGS){
    readIndex = 0;
}
averagePotValue = total / NUM_READINGS;
}