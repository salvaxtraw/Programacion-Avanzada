#include <Arduino.h>
#include <Wire.h>
#include "indice.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
bool pantalla = false;

void displayInit(){
    Wire.begin(19,18,400000);
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    oled.clearDisplay();
    oled.display();
}

void textobienvenida(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(18,25);
    oled.print("Hola, bienvenido!");
    oled.display();
}
void menu(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Menu:");
    oled.setCursor(0,20);
    oled.print("1. Opcion 1");
    oled.setCursor(0,40);
    oled.print("2. Opcion 2");
    oled.display();
}
void selector(){
    oled.fillRect(0, 20 + 20*i, 128, 20, SSD1306_INVERSE);
    oled.display();
}
void op1(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Opcion 1 seleccionada");
    oled.display();
}
void op2(){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0,0);
    oled.print("Opcion 2 seleccionada");
    oled.display();
}

void limpiarPantalla(){
    oled.clearDisplay();
    oled.display();
}
void apagarPantalla(){
    oled.ssd1306_command(SSD1306_DISPLAYOFF);
}
void encenderPantalla(){
    oled.ssd1306_command(SSD1306_DISPLAYON);
}