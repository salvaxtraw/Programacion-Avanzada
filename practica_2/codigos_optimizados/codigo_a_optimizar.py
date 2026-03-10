# python_no_opt.py
# Versión: 1.1.0
# Autor: Salvador Estrada Pulido
# Fecha: 2026-03-09
# Descripción:
# Calcula las frecuencias de una lista de enteros, encuentra el modo
# y calcula la suma de los dígitos del modo.
#
# Entrada:
# Lista de números enteros
#
# Salida:
# Frecuencias
# Modo
# Suma de dígitos del modo
# Tiempo de ejecución (para benchmarking)
# MOD: v1.1.0 — optimización usando diccionario O(n) y medición de tiempo

import time
# inicio del benchmark
inicio = time.time()
# lista de números
numeros = [3, -1, 0, 5, -7, 0, 2, 3, 3, -1, 5, 5, 5]
# diccionario de frecuencias
frecuencias = {}
# recorrer lista
for n in numeros:
    # si ya existe incrementar
    if n in frecuencias:
        frecuencias[n] += 1
    # si no existe inicializar
    else:
        frecuencias[n] = 1
# variables para el modo
modo = None
max_cuenta = -1
# recorrer diccionario
for valor, cuenta in frecuencias.items():
    # comparar frecuencia
    if cuenta > max_cuenta:
        # actualizar valores
        max_cuenta = cuenta
        modo = valor
# copia del modo
x = modo
# convertir a positivo
if x < 0:
    x = -x
# suma de dígitos
suma_digitos = 0
while x > 0:
    suma_digitos = suma_digitos + (x % 10)
    x = x // 10
# fin del benchmark
fin = time.time()
tiempo = (fin - inicio) * 1000
# resultados
print("Frecuencias:", frecuencias)
print("Modo:", modo, "con cuenta:", max_cuenta)
print("Suma de dígitos del modo:", suma_digitos)
print("Tiempo de ejecución (ms):", tiempo)
