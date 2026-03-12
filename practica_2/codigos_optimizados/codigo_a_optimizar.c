/*
Versión: 1.3.0
Autor: Saldaña Ramirez Cesar Augusto
Fecha: 2026-03-12

Descripción:
Encuentra todos los números primos desde 2 hasta N,
cuenta cuántos existen, suma su valor y clasifica
primos pares e impares.

Entrada:
N (entero)

Salida:
Número de primos
Suma de primos
Primos pares
Primos impares
Tiempo de ejecución
*/

/* 
MOD: v1.3.0 — Se arreglaron multiples problemas, entre ellos:
- Comentarios de cambio donde no hubo cambio.
- Codigo que realmente no funciona, se copio uno incorrecto y no 
se verifico antes de subirse al repositorio.
- Se eliminaron 2 if en if(es_primo) para solo agregar uno al inicio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    clock_t inicio = clock();
    int N = 1000;
    int count_primos = 0;
    long long suma_primos = 0;
    int primos_pares = 0;
    int primos_impares = 0;
    if (N >= 2) { // Se agrego este if al inicio para descartar el 2.
        count_primos++;
        suma_primos += 2;
        primos_pares = 1;
    }
    for (int m = 3; m <= N; m += 2) {
        int es_primo = 1;
        int d = 3; // Aqui estaba el comentario mal puesto.
        while (d * d <= m) {
            if (m % d == 0) {
                es_primo = 0;
                break;
            }
            d += 2; // Aqui debia ir el comentario de la v1.2.0 y v1.2.1
        }
    if (es_primo) {
        count_primos++;
        suma_primos += m;
        primos_impares++;
        } // Se eliminarion 2 if
    }
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC * 1000;
    printf("Primos encontrados: %d\n", count_primos);
    printf("Suma de primos: %lld\n", suma_primos);
    printf("Primos pares: %d\n", primos_pares);
    printf("Primos impares: %d\n", primos_impares);
    printf("Tiempo de ejecucion (ms): %.3f\n", tiempo);
    return 0;
}

/*
El codigo corre en 0.000ms ya que corre aproximadamente en 0.02ms lo que 
es mas veloz que un tick (En lo que se mide el tiempo en esta version).
*/
