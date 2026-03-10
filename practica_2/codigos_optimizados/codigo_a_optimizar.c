/* c_no_opt.c
   Versión: 1.1.0
   Autores: Estrada Pulido Salvador y Saldaña Ramírez César Augusto
   Fecha: 2026-03-09
   Descripción:
   El programa encuentra todos los números primos desde 2 hasta N,
   cuenta cuántos existen, suma su valor y clasifica primos pares
   e impares.
   Entrada:
   Un número entero N
   Salida:
   Cantidad de números primos
   Suma de primos
   Cantidad de primos pares
   Cantidad de primos impares
*/
/* MOD: v1.1.0 — optimización del algoritmo de primalidad usando sqrt(n)
   y eliminación de ramas redundantes */

#include <stdio.h>
#include <stdlib.h>

int main() {
    /* límite superior */
    int N = 1000;
    /* contador de primos */
    int count_primos = 0;
    /* suma de primos */
    long long suma_primos = 0;
    /* contador primos pares */
    int primos_pares = 0;
    /* contador primos impares */
    int primos_impares = 0;
    /* recorrer números desde 2 hasta N */
    for (int m = 2; m <= N; m++) {
        /* asumir que es primo */
        int es_primo = 1;
        /* divisor inicial */
        int d = 2;
        /* MOD: v1.1.0 — solo probar hasta sqrt(m) */
        while (d * d <= m) {
            /* verificar divisibilidad */
            if (m % d == 0) {
                /* no es primo */
                es_primo = 0;
                /* salir del ciclo */
                break;
            }
            /* siguiente divisor */
            d++;
        }
        /* si es primo */
        if (es_primo) {
            /* incrementar contador */
            count_primos++;
            /* sumar primo */
            suma_primos += m;
            /* clasificar primo */
            if (m % 2 == 0) {
                primos_pares++;
            } else {
                primos_impares++;
            }
        }
    }
    /* imprimir resultados */
    printf("Primos encontrados: %d\n", count_primos);
    printf("Suma de primos: %lld\n", suma_primos);
    printf("Primos pares: %d\n", primos_pares);
    printf("Primos impares: %d\n", primos_impares);
    return 0;
}
