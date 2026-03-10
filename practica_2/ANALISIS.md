# ANALISIS

## Comparación de optimización

Este documento describe las mejoras realizadas en los programas
`python_no_opt.py` y `c_no_opt.c`.

---

# Python

## Versión original (1.0.0)

Complejidad aproximada:

O(n²)

Motivo:

* El programa buscaba valores dentro de una lista usando bucles `while`.
* Cada vez que encontraba un nuevo valor volvía a recorrer toda la lista para contar apariciones.
* Esto generaba múltiples recorridos de la lista y aumentaba el tiempo de ejecución.

---

## Versión optimizada (1.1.0)

Complejidad:

O(n)

Mejoras aplicadas:

* Se reemplazó la lista de tuplas por un diccionario.
* Los diccionarios permiten inserción y búsqueda en tiempo constante promedio.
* Se eliminaron los bucles `while` anidados.

Impacto:

La versión optimizada reduce significativamente el tiempo de ejecución,
especialmente cuando la lista de números es grande.

---

# C

## Versión original (1.0.0)

Complejidad aproximada:

O(N²)

Motivo:

* Para verificar si un número era primo se probaban todos los divisores
  desde 2 hasta m-1.
* El algoritmo continuaba evaluando divisores incluso después de encontrar uno.

---

## Versión optimizada (1.1.0)

Complejidad:

O(N√N)

Mejoras aplicadas:

* Se limita la búsqueda de divisores hasta √m.
* Se usa `break` para detener la búsqueda cuando se encuentra un divisor.

Impacto:

La reducción del número de divisores evaluados disminuye considerablemente
el tiempo de ejecución del programa.

---

# Resultados

Los resultados de las pruebas de rendimiento se encuentran en:

results/results.csv

Los datos muestran que la versión optimizada presenta tiempos de ejecución
menores en comparación con la versión original.
