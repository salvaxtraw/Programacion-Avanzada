#include <Arduino.h>
#include "indice.h"

int i = 0;
const int numOpciones = 4;
unsigned long tiempo_presionado = 0;
bool presionado = false;
bool menu_activo = false;

void up(){
    i++;
    if (i >= numOpciones) {
        i = 1;
    }
}
void down(){
    i--;
    if (i <= 0) {
        i = numOpciones - 1;
    }
}