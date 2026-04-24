# Conceptos de Python Aprendidos

## Sockets y Redes (`socket`)
Se profundizaron las funciones fundamentales para la comunicación en red:
- `socket.socket()`: Instanciación del objeto de comunicación.
- `bind()` y `listen()`: Configuración del lado del servidor.
- `accept()`: Bloqueo de ejecución hasta que un cliente se conecta.
- `sendall()` vs `send()`: Se prefirió `sendall` para asegurar la transmisión de buffers completos.

## Manejo de Archivos y Flujos
Para la transferencia de archivos, se implementó el envío por **chunks** (bloques):
- `open(file, 'rb')`: Lectura en modo binario para evitar corrupción de datos.
- Lectura en bloques de 4096 bytes para optimizar el uso de memoria RAM.

## Hashing e Integridad (`hashlib`)
Uso del algoritmo **SHA256** para validar que el archivo recibido es idéntico al enviado.
```python
import hashlib
hash_func = hashlib.sha256()
hash_func.update(data)
print(hash_func.hexdigest())
