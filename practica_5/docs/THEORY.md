# Fundamentos de Redes y Sockets

## ¿Qué es un Socket?
Un **socket** es un punto final (endpoint) en un canal de comunicación bidireccional. Se define técnicamente por la combinación de una dirección IP y un número de puerto. En el modelo OSI, los sockets operan principalmente en la capa de Transporte, permitiendo que las aplicaciones envíen y reciban datos a través de la red.

## Protocolos de Transporte: TCP vs UDP

| Característica | TCP (Transmission Control Protocol) | UDP (User Datagram Protocol) |
| :--- | :--- | :--- |
| **Orientación** | Orientado a conexión (Handshake) | Sin conexión (Best-effort) |
| **Fiabilidad** | Alta (retransmisión de paquetes) | Baja (puede haber pérdida) |
| **Orden** | Garantiza el orden de llegada | No garantiza el orden |
| **Uso Ideal** | Transferencia de archivos, Chat, SSH | Streaming, Juegos online, VoIP |

## Puertos y Direcciones IP
- **Dirección IP:** Identificador único de un host en una red (IPv4 o IPv6).
- **Puertos:** Identificadores numéricos (0-65535) que dirigen el tráfico a procesos específicos.
    - **Puertos de Usuario:** 1024 - 49151.
    - **Puertos Dinámicos/Privados:** 49152 - 65535.

## NAT y Firewalls
- **NAT (Network Address Translation):** Método para mapear un espacio de direcciones IP privadas a una pública. Es la razón por la cual dos dispositivos en redes domésticas diferentes no suelen verse directamente sin configuración extra.
- **Firewalls:** Software o hardware que filtra el tráfico. Para este proyecto, es esencial permitir el tráfico entrante en el puerto elegido (ej. 5000).

## Seguridad Básica
En transmisiones punto a punto, la seguridad se basa en el cifrado de extremo a extremo. El uso de protocolos como **TLS/SSL** sobre los sockets TCP asegura que la información no sea leída por terceros (*sniffing*).
