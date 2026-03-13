#include <Arduino.h>
#include "display.h"
#include "botones.h"
#include "time_down.h"
#include "indice.h"

void setup() {
  displayInit();
  timer_init();
  botonesInit();
}
enum estado {BIENVENIDA, MENU, OPCION1, OPCION2, HOLD};
void loop() {
  static estado estado_actual = BIENVENIDA;
  switch (estado_actual) {
    case BIENVENIDA:
    static bool dibujado = false;
    static unsigned long tiempo_presionado = 0;
    if(!dibujado){
      textobienvenida();
      timer_init();
      dibujado = true;
    }
    if(enter()){
      if(tiempo_presionado == 0){
        tiempo_presionado = millis();
      }
      if(millis() - tiempo_presionado > 5000){ 
        estado_actual = MENU;
        dibujado = false;
        tiempo_presionado = 0;
        timer_init();
      }
    }
      else {
        tiempo_presionado = 0;
      }
      if (timer_ready()){
        apagarPantalla();
        estado_actual = HOLD;
        dibujado = false;
        tiempo_presionado = 0;
      }
    break;
    case MENU:
      static bool dibujado_menu = false;
      if(!dibujado_menu){
        menu();
        selector();
        dibujado_menu = true;
      }
      if (enter()) {
        delay(200);
        dibujado_menu = false;
        if (i == 0) estado_actual = OPCION1;
        else if (i == 1) estado_actual = OPCION2;
        timer_init();
      }
      else if (up_button()) {
        delay(200);
        next();
        menu();
        selector();
        timer_init();
      }
      else if (down_button()) {
        delay(200);
        back();
        menu();
        selector();
        timer_init();
      }
      else if (menu_ready()) {
        apagarPantalla();
        dibujado_menu = false;
        estado_actual = HOLD;
      }
    break;
    case OPCION1:
      op1();
      if (enter()) {
        delay(200);
        estado_actual = MENU;
        timer_init();
      }
      else if (menu_ready()) {
        apagarPantalla();
        estado_actual = HOLD;
      }
    break;
    case OPCION2:
      op2();
      if (enter()) {
        delay(200);
        estado_actual = MENU;
        timer_init();
      }
      else if (menu_ready()) {
        apagarPantalla();
        estado_actual = HOLD;
      }
    break;
    case HOLD:
    if (enter() || up_button() || down_button()) {
      estado_actual = BIENVENIDA;
      encenderPantalla();
      timer_init();
    }

break;
  }
}
