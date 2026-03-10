# python_no_opt.py
# Versión: 1.1.0
# Autores: Estrada Pulido Salvador y Saldaña Ramírez César Augusto 
# Fecha: 2026-03-09
# Descripción:
# Este programa calcula la frecuencia de una lista de números,
# determina el valor modal y calcula la suma de los dígitos del modo.
#
# Entrada:
# Lista de números enteros
#
# Salida:
# Frecuencias de cada número
# Valor modal
# Suma de los dígitos del modo
# MOD: v1.1.0 — optimización usando diccionario en lugar de búsqueda O(n²)

# Lista de números de ejemplo
numeros = [3, -1, 0, 5, -7, 0, 2, 3, 3, -1, 5, 5, 5]
# Diccionario para almacenar frecuencias
frecuencias = {}
# Recorrer lista de números
for n in numeros:
    # Si el número ya está en el diccionario
    if n in frecuencias:
        # Incrementar contador
        frecuencias[n] = frecuencias[n] + 1
    else:
        # Inicializar contador
        frecuencias[n] = 1
# Buscar el modo
modo = None
# Contador máximo
max_cuenta = -1
# Recorrer diccionario
for valor, cuenta in frecuencias.items():
    # Comparar frecuencia actual
    if cuenta > max_cuenta:
        # Actualizar máximo
        max_cuenta = cuenta
        # Guardar modo
        modo = valor
# Copia del modo para manipulación
x = modo
# Si es negativo convertir a positivo
if x < 0:
    x = -x
# Suma de dígitos
suma_digitos = 0
# Mientras queden dígitos
while x > 0:
    # Agregar último dígito
    suma_digitos = suma_digitos + (x % 10)
    # Eliminar último dígito
    x = x // 10
# Salida de resultados
print("Frecuencias:", frecuencias)
print("Modo:", modo, "con cuenta:", max_cuenta)
print("Suma de dígitos del modo:", suma_digitos)
