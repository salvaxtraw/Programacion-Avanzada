# Chat Punto a Punto por Wi‑Fi y Transferencia de Archivos

## Resumen y Objetivo
Este proyecto consiste en una aplicación desarrollada en Python que establece una comunicación cliente-servidor mediante **Sockets TCP**. Permite el intercambio de mensajes en tiempo real y la transferencia de archivos entre dos equipos conectados a la misma red local o mediante un punto de acceso (Hotspot).

## Estructura del Repositorio

```text
/
├── README.md
├── .gitignore
├── requirements.txt
├── CHANGELOG.md
├── src/
│   ├── server_chat.py
│   ├── client_chat.py
│   ├── file_transfer.py
│   └── utils.py
├── docs/
│   ├── THEORY.md
│   ├── DECISION.md
│   └── LEARNED_PYTHON.md
├── images/
│   └── tests/
├── results/
│   ├── logs/
│   └── received/
└── scripts/
    ├── create_hotspot.sh
    └── create_hotspot_win.bat
```

## Cómo Replicar las Pruebas

Para evaluar el correcto funcionamiento del proyecto, sigue este flujo de pruebas:

### Prueba 1: Chat de Texto Básico
1. **Inicia el servidor:** `python src/server_chat.py --host 0.0.0.0 --port 5000`
2. **Conecta el cliente:** `python src/client_chat.py --host <IP_SERVIDOR> --port 5000`
3. **Interacción:** Escribe un mensaje en la terminal del cliente y presiona *Enter*. Verifica que el mensaje aparezca en la terminal del servidor y viceversa.
4. **Cierre:** Escribe `salir` o `exit` en cualquiera de las terminales para cerrar la conexión de forma segura.

### Prueba 2: Transferencia de Archivos (Mejora)
1. **Prepara un archivo de prueba:** Crea un archivo de texto ligero (ej. `test.txt`) en el equipo cliente.
2. **Inicia el servidor:** (Igual que en la Prueba 1).
3. **Envía el archivo:** `python src/file_transfer.py --host <IP_SERVIDOR> --port 5000 --file test.txt`
4. **Verificación en consola:** Observa que el cliente imprima el tamaño y el hash SHA256 del archivo enviado. El servidor debe imprimir "Recibiendo archivo..." y confirmar que el hash coincide.

---

## Resultados y Evidencia

Una vez realizadas las pruebas, el proyecto generará automáticamente la siguiente evidencia para su revisión:

* **Archivos Recibidos (`results/received/`):** Aquí se guardarán los archivos transferidos mediante `file_transfer.py`. Puedes comparar el archivo original con este para verificar que no haya corrupción de datos.

* **Logs de Ejecución (`results/logs/`):**
  * `server_test1.log`: Registra cuándo el servidor empezó a escuchar, qué IP se conectó, eventos de recepción de archivos, validación de checksums (SHA256) y errores de conexión.
  * `client_test1.log`: Registra el intento de conexión, el envío exitoso de bloques de datos y tiempos de respuesta.
  *(Nota: Estos archivos documentan la trazabilidad técnica de las sesiones pasadas sin necesidad de ejecutar el código nuevamente).*

* **Capturas de Pantalla (`images/tests/`):**
  * `hotspot_conn.png` / `same_network_conn.png`: Demuestran la obtención de las direcciones IP mediante comandos como `ipconfig` o `ip a`.
  * `client_server_terminal.png`: Muestra las dos terminales (cliente y servidor) interactuando en tiempo real.
