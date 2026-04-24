# Registro de Decisiones Técnicas (DRL)

## Método de Conexión Elegido
Se ha seleccionado la conexión mediante **Hotspot (Punto de Acceso Móvil)** generado por uno de los equipos.

## Justificación
1. **Control del Entorno:** Al crear una red local propia, se evitan las restricciones de aislamiento de clientes (*Client Isolation*) comunes en redes universitarias o públicas.
2. **Estabilidad:** Menor interferencia y latencia en comparación con redes saturadas.
3. **Simplicidad:** Permite obtener direcciones IP estáticas o conocidas rápidamente.

## Comandos Utilizados
Para identificar las interfaces y configurar la red, se emplearon:

### En Windows:
- `ipconfig`: Para verificar la dirección IPv4 asignada por el hotspot.
- `netsh wlan show interfaces`: Para ver el estado de la conexión inalámbrica.

### En Linux/macOS:
- `ip a` o `ifconfig`: Para localizar la interfaz `wlan0`.

## Problemas Encontrados y Soluciones
- **Problema:** El servidor no recibía conexiones del cliente.
- **Solución:** Se deshabilitó temporalmente el Firewall para redes privadas y se verificó que el servidor estuviera escuchando en `0.0.0.0` para aceptar conexiones de cualquier interfaz.
- **Problema:** El puerto se quedaba "bloqueado" al reiniciar el script.
- **Solución:** Se implementó la opción `SO_REUSEADDR` en la configuración del socket en Python.
