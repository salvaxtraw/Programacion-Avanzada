# server_chat.py
# Versión: 1.0.1
# Autor: Saldaña Ramirez Cesar Augusto
# Fecha: 2026-04-24
# Descripción:
# Debera encender un servidor por el cual otra computadora se pueda conectar usando threading para enviar
# un mensaje de texto simple. 

import socket, threading

Host = '0.0.0.0' # Segun la documentacion consultada, el puerto EN EL HOST debe ser este para evotar errores
Port = 5000 

# En las diapositivas mostradas en la ultima clase se mostro la estructura basica de un socket server
# socket - bind - listen - recv - close

def iniciar_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # Socket
    server.bind((Host, Port)) # Bind
    server.listen(1) # Listen
    print(f"(Servidor) Esperando coneccion con el cliente...")

    con, addr = server.accept()
    print(f"(Servidor) Conectado")

    def recv():
        while True:
            try:
                data = con.recv(1024).decode()
                if not data:
                    break
                print(f"\n(Cliente) {data}")
            except:
                break

    threading.Thread(target=recv, daemon=True)
    while True:
        msg = input()
        con.send(msg.encode())