# client_chat.py
# Versión: 1.0.0
# Autor: Saldaña Ramirez Cesar Augusto
# Fecha: 2026-04-24
# Descripción:
# Debera conectarse a un servidor por el cual pueda mandar un mensaje de texto usando threading

import socket, threading

def iniciar_cliente():
    cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
    cliente.connect(('192.168.100.3', 5000)) # La ip viene de ipconfig en cmd
    print(f"(Cliente) Conexion completada...")

    def recv():
        while True:
            try:
                data = cliente.recv(1024).decode()
                if not data:
                    break
                print(f"\n(Servidor) {data}")
            except:
                break

    threading.Thread(target=recv, daemon=True).start()
    while True:
        msg = input()
        cliente.send(msg.encode())