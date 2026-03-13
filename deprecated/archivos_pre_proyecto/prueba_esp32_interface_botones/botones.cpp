#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define up 22
#define start_select 23
#define down 21

void botonesInit() {
  pinMode(up, INPUT_PULLUP);
  pinMode(start_select, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
}

bool enter() { 
    return digitalRead(start_select) == LOW;
}
bool up_button() {
    return digitalRead(up) == LOW;
}
bool down_button() {
    return digitalRead(down) == LOW;
}
