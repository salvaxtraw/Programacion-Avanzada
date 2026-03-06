#include <Arduino.h>

const int potPin = 34;

int a = 32;
int b = 26;
int c = 21;
int d = 22;
int e = 23;
int f = 33;
int g = 25;

void display(int n){
  switch(n){
    case 9:
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,0);
    break;
    case 8:
      digitalWrite(a,0);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,0);
    break;
    case 7:
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,0);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,0);
      digitalWrite(g,1);
    break;
    case 6:
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,1);
    break;
    case 5:
      digitalWrite(a,0);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
    break;
    case 4:
      digitalWrite(a,1);
      digitalWrite(b,0);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
    break;
    case 3:
      digitalWrite(a,1);
      digitalWrite(b,0);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,1);
    break;
    case 2:
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,0);
      digitalWrite(e,0);
      digitalWrite(f,0);
      digitalWrite(g,0);
    break;
    case 1:
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,1);
      digitalWrite(f,1);
      digitalWrite(g,1);
    break;
    case 0:
      digitalWrite(a,1);
      digitalWrite(b,1);
      digitalWrite(c,1);
      digitalWrite(d,1);
      digitalWrite(e,0);
      digitalWrite(f,1);
      digitalWrite(g,1);
    break;
  }
}
void setup(){
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void loop(){
  int valor = analogRead(potPin);
  int numero = valor / 409;
  if(numero > 9) numero = 9;
  display(numero);
}
