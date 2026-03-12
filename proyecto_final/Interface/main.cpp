#include <Arduino.h>
#include "display.h"
#include "botones.h"
#include "time_down.h"
#include "indice.h"
#include "potenciometro.h"

void setup() {
  displayInit();
  timer_init();
  botonesInit();
  medicion();
}
enum estado {BIENVENIDA, MENU, CONFIG1, CONFIG2, SALUD1, SALUD2, HOLD, 
  CONFIG, SALUD, REGRESAR1, REGRESAR2, PREGUNTAR};
void loop() {
  lectura();
  static estado estado_actual = BIENVENIDA;
  static bool dibujado = false;
  switch (estado_actual) {
    case BIENVENIDA:
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
    else tiempo_presionado = 0;
    if (timer_ready() && !enter()) {
      dibujado = false;
      estado_actual = HOLD;
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
        if (i == 1) estado_actual = CONFIG;
        else if (i == 2) estado_actual = SALUD;
        else if (i == 3) estado_actual = PREGUNTAR;
        timer_init();
      }
      else if (up_button()) {
        up();
        menu();
        selector();
        timer_init();
      }
      else if (down_button()) {
        down();
        menu();
        selector();
        timer_init();
      }
      else if (timer_ready()) {
        estado_actual = HOLD;
      }
      break;
      case CONFIG:
      if(!dibujado_menu){
        config();
        selector();
        dibujado_menu = true;
      }
      if (enter()) {
        delay(200);
        dibujado_menu = false;
        if (i == 1) estado_actual = CONFIG1;
        else if (i == 2) estado_actual = CONFIG2;
        else if (i == 3) estado_actual = REGRESAR1;
        timer_init();
      }
      else if (up_button()) {
        up();
        config();
        selector();
        timer_init();
      }
      else if (down_button()) {
        down();
        config();
        selector();
        timer_init();
      }
      else if (timer_ready()) {
        estado_actual = HOLD;
      }
      break;
      case CONFIG1:
      op1();
      if (timer_ready()) {
        estado_actual = HOLD;
      }
      if (enter() || up_button() || down_button()) {
        estado_actual = CONFIG;
        encenderPantalla();
        timer_init();
      }
      break;
      case CONFIG2:
      op2();
      if (timer_ready()) {
        estado_actual = HOLD;
      }
      if (enter() || up_button() || down_button()) {
        estado_actual = CONFIG;
        encenderPantalla();
        timer_init();
      }
      break;
      case REGRESAR1:
        estado_actual = MENU;
        encenderPantalla();
        timer_init();
      break;
      case SALUD:
      if(!dibujado_menu){
        salud();
        selector();
        dibujado_menu = true;
      }
      if (enter()) {
        delay(200);
        dibujado_menu = false;
        if (i == 1) estado_actual = SALUD1;
        else if (i == 2) estado_actual = SALUD2;
        else if (i == 3) estado_actual = REGRESAR2;
        timer_init();
      }
      else if (up_button()) {
        up();
        salud();
        selector();
        timer_init();
      }
      else if (down_button()) {
        down();
        salud();
        selector();
        timer_init();
      }
      else if (timer_ready()) {
        estado_actual = HOLD;
      }
      break;
      case SALUD1:
      pulso();
      if (timer_ready()) {
        estado_actual = HOLD;
      }
      if (enter() || up_button() || down_button()) {
        estado_actual = SALUD;
        encenderPantalla();
        timer_init();
      }
      break;
      case SALUD2:
      op2();
      if (timer_ready()) {
        estado_actual = HOLD;
      }
      if (enter() || up_button() || down_button()) {
        estado_actual = SALUD;
        encenderPantalla();
        timer_init();
      }
      break;
      case REGRESAR2:
        estado_actual = MENU;
        encenderPantalla();
        timer_init();
      break;
      case PREGUNTAR:
      if(!dibujado_menu){
        preguntarApagar();
        selector();
        dibujado_menu = true;
      }
      if (enter()) {
        delay(200);
        dibujado_menu = false;
        if (i == 1) {
          apagarPantalla();
          if(enter()){
            if(tiempo_presionado == 0){
              tiempo_presionado = millis();
            }
            if(millis() - tiempo_presionado > 5000){ 
              encenderPantalla();
              estado_actual = BIENVENIDA;
            }
          }
        }
        else if (i == 2) estado_actual = MENU;
        else if (i == 3) estado_actual = HOLD;
        }
        else if (up_button()) {
        up();
        preguntarApagar();
        selector();
        timer_init();
      }
      else if (down_button()) {
        down();
        preguntarApagar();
        selector();
        timer_init();
      }
      break;
      case HOLD:
      hold();
      if (enter() || up_button() || down_button()) {
        estado_actual = BIENVENIDA;
        encenderPantalla();
        timer_init();
      }
      break;
  }
}
