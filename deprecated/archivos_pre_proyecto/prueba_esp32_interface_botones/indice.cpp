#include <Arduino.h>
#include "indice.h"

int i = 0;
const int numOpciones = 2;
unsigned long tiempo_presionado = 0;
bool presionado = false;
bool menu_activo = false;

void next(){
    i++;
    if (i >= numOpciones) {
        i = 2;
    }
}
void back(){
    i--;
    if (i < 0) {
        i = 1;
    }
}