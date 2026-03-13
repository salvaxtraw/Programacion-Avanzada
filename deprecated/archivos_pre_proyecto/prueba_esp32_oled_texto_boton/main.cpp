#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PUSH1 33

Adafruit_SSD1306 oled(128, 64, &Wire, -1);

unsigned long pressStart = 0;

void setup() {
Wire.begin(21,22);
pinMode(PUSH1, INPUT_PULLUP);
oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {

if (digitalRead(PUSH1) == LOW && pressStart == 0) {
pressStart = millis();
oled.clearDisplay();
oled.setTextSize(1);
oled.setTextColor(SSD1306_WHITE);
oled.setCursor(10,25);
oled.print("Ping Ling");
oled.display();
}

if (digitalRead(PUSH1) == LOW && millis() - pressStart >= 10000) {
oled.clearDisplay();
oled.setTextSize(1);
oled.setTextColor(SSD1306_WHITE);
oled.setCursor(10,25);
oled.print("Texto secreto :D");
oled.display();
}

if (digitalRead(PUSH1) == HIGH && pressStart != 0) {
pressStart = 0;
oled.clearDisplay();
oled.display();
}
}
