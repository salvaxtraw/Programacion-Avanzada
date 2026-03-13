#include <Arduino.h>
#include "time_down.h"

unsigned long ultimo_push = 0;
const unsigned long menu = 5000;
const unsigned long timeoutms = 15000;

void timer_init(){
    ultimo_push = millis();
}

bool timer_ready(){
    if(millis() - ultimo_push >= timeoutms){
        ultimo_push = millis();
        return true;
    }
    return false;
}
bool menu_ready(){
    if(millis() - ultimo_push >= menu){
        return true;
    }
    return false;
}