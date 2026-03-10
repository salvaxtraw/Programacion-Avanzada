/* c_no_opt.c
   Versión: 1.1.0
   Autor: Salvador Estrada Pulido
   Fecha: 2026-03-09

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

/* MOD: v1.1.0 — optimización usando sqrt(n) y medición de tiempo */
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
    for (int m = 2; m <= N; m++) {
        int es_primo = 1;
        int d = 2;
        /* probar divisores hasta sqrt(m) */
        while (d * d <= m) {
            if (m % d == 0) {
                es_primo = 0;
                break;
            }
            d++;
        }
        if (es_primo) {
            count_primos++;
            suma_primos += m;
            if (m % 2 == 0) {
                primos_pares++;
            } else {
                primos_impares++;
            }
        }
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
