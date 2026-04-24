# server_chat.py
# Versión: 1.0.0
# Autor: Saldaña Ramirez Cesar Augusto
# Fecha: 2026-04-23
# Descripción:
# Debera encender un servidor por el cual otra computadora se pueda conectar usando threading para enviar
# un mensaje de texto simple. 

import socket, threading

Host = '0.0.0.0' # Segun la documentacion consultada, el puerto EN EL HOST debe ser este para evotar errores
Port = 5000 

def iniciar_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((Host, Port))
    server.listen(1)
    print(f"Esperando coneccion con el cliente...")