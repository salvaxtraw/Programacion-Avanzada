#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PUSH1 22
#define PUSH2 23
#define PUSH3 21
#define PUSH4 17

#define rojo 25
#define verde 26
#define amarillo 27
#define azul 32

#define SDA 19
#define SCL 18

Adafruit_SSD1306 oled(128, 64, &Wire, -1);

void setup() {
  Wire.begin(SDA, SCL);
  pinMode(PUSH1, INPUT_PULLUP);
  pinMode(PUSH2, INPUT_PULLUP);
  pinMode(PUSH3, INPUT_PULLUP);
  pinMode(PUSH4, INPUT_PULLUP);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(azul, OUTPUT);
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
}

void loop() {
  bool b1 = digitalRead(PUSH1) == LOW;
  bool b2 = digitalRead(PUSH2) == LOW;
  bool b3 = digitalRead(PUSH3) == LOW;
  bool b4 = digitalRead(PUSH4) == LOW;
  digitalWrite(rojo, b1 ? HIGH : LOW);
  digitalWrite(verde, b2 ? HIGH : LOW);
  digitalWrite(amarillo, b3 ? HIGH : LOW);
  digitalWrite(azul, b4 ? HIGH : LOW);
  oled.clearDisplay();
  oled.setCursor(0,0);
  oled.print("Led turned on:");
  int y = 10;
  if (b1) {
    oled.setCursor(0,y);
    oled.print("Red =7w7=");
    y += 10;
  }
  if (b2) {
    oled.setCursor(0,y);
    oled.print("Green =*w*=");
    y += 10;
  }
  if (b3) {
    oled.setCursor(0,y);
    oled.print("Yellow =^w^=");
    y += 10;
  }
  if (b4) {
    oled.setCursor(0,y);
    oled.print("Blue =UwU=");
    y += 10;
  }
  if (b1 && b2 && b3 && b4) {
    oled.clearDisplay();
    oled.setCursor(0,0);
    oled.print("Led turned on:");
    oled.setCursor(0,10);
    oled.print("All leds are on!!");
    oled.setCursor(0,20);
    oled.print("=OwO=");
  }
  if (!b1 && !b2 && !b3 && !b4) {
    oled.clearDisplay();
    oled.setCursor(0,0);
    oled.print("Led turned on:");
    oled.setCursor(0,10);
    oled.print("No leds are on =UnU=");
  }
  oled.display();
}
