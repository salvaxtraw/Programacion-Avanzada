# `Notas de Documentación del Código`

### 1. Inicialización y Configuración
Se utiliza un **diccionario** `config` y el módulo `argparse`. Esto permite que el script sea flexible sin necesidad de editar el código fuente cada vez que se cambia la duración del experimento.

### 2. Conexión y Simulación
La función `simulate_reading` utiliza el módulo `math` y `random` para generar señales realistas. La temperatura sigue una deriva lineal con ruido gaussiano, mientras que el LDR sigue una función senoidal para simular ciclos de luz, con inyecciones aleatorias de picos para probar la **Mejora C**.

### 3. Bucle de Adquisición
Utiliza una estructura `while` controlada por `time.time()`. Cada lectura se almacena en una **lista de tuplas**, lo que garantiza la inmutabilidad de cada registro individual una vez capturado.

### 4. Procesamiento y Eventos
Se recorre la lista de lecturas para separar los canales de datos y detectar disparos de umbral. Se emplea el módulo `statistics` para obtener la desviación estándar y la media, ignorando valores nulos (`NaN`).

### 5. Guardado Atómico
Se implementó una técnica de escritura en archivo temporal seguida de un renombrado (`os.replace`). Esto asegura que si el sistema falla a mitad de la escritura, el archivo original no quede corrupto o vacío.
