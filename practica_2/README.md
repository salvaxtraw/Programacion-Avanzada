# Optimización de Código – Python y C

## Descripción

Este repositorio contiene los programas base en **Python** y **C** utilizados para una actividad de optimización de código.
El objetivo del ejercicio es analizar programas existentes, optimizarlos, documentar los cambios y medir el impacto de dichas optimizaciones en el rendimiento.

Los archivos mantienen **exactamente el mismo nombre** durante todo el proceso.
Cuando se realiza una mejora, únicamente se actualiza la **versión en la cabecera del archivo**.

---

# Estructura del repositorio

```
.
├── README.md
├── python_no_opt.py
├── c_no_opt.c
├── CHANGELOG.md
├── ANALYSIS.md
├── results/
│   └── results.csv
└── tests/
    ├── test_input.txt
    └── expected_output.txt
```

---

# Archivos principales

## python_no_opt.py

Programa que:

1. Analiza una lista de números enteros.
2. Calcula la frecuencia de cada número.
3. Determina el valor modal (número que más se repite).
4. Calcula la suma de los dígitos del modo.

### Optimización aplicada

Versión original:

* Uso de listas y múltiples bucles `while`.
* Complejidad aproximada: **O(n²)**.

Versión optimizada:

* Uso de diccionarios para almacenar frecuencias.
* Eliminación de recorridos redundantes.

Nueva complejidad:

**O(n)**

---

## c_no_opt.c

Programa que:

1. Genera números desde 2 hasta **N**.
2. Determina cuáles son primos.
3. Cuenta el número de primos encontrados.
4. Calcula la suma de todos los primos.
5. Clasifica los primos en pares e impares.

### Optimización aplicada

Versión original:

* Verificación de primalidad probando divisores desde **2 hasta m-1**.
* Complejidad aproximada: **O(N²)**.

Versión optimizada:

* Solo se prueban divisores hasta **√m**.
* Se usa `break` para terminar la búsqueda cuando se encuentra divisor.

Nueva complejidad:

**O(N√N)**

---

# Resultados de rendimiento

Los resultados de las pruebas de rendimiento se almacenan en:

```
results/results.csv
```

Cada programa se ejecutó múltiples veces para comparar el tiempo de ejecución entre la versión original y la versión optimizada.

Ejemplo de estructura del archivo:

```
programa,version,run,tiempo_ms
python_no_opt,1.1.0,1,7.2
python_no_opt,1.1.0,2,6.9
c_no_opt,1.1.0,1,33
c_no_opt,1.1.0,2,32
```

---

# Versionado

El proyecto utiliza versionado semántico simple:

```
MAJOR.MINOR.PATCH
```

Ejemplo:

```
1.0.0
1.1.0
```

Las versiones se actualizan **directamente en la cabecera de cada archivo**.

---

# Registro de cambios

Los cambios realizados se documentan en:

```
CHANGELOG.md
```

Cada entrada incluye:

* archivo modificado
* versión anterior
* nueva versión
* resumen de los cambios

---

# Análisis de optimización

El análisis completo de las mejoras implementadas se encuentra en:

```
ANALYSIS.md
```

Este documento explica:

* la complejidad del algoritmo original
* las optimizaciones aplicadas
* el impacto en el rendimiento

---

# Pruebas

Los archivos de prueba se encuentran en:

```
tests/
```

Incluyen ejemplos de entrada y resultados esperados para validar el funcionamiento del programa.

---

# Ejecución

## Python

```
python python_no_opt.py
```

---

## C

Compilar:

```
gcc c_no_opt.c -o primos
```

Ejecutar:

```
./primos
```

---

# Autores

Estrada Pulido Salvador y Saldaña Ramírez César Augusto

Facultad de Ingeniería en Instrumentación Electrónica
