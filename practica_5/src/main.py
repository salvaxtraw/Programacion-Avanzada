# main.py
# Versión: 1.0.1
# Autor: Saldaña Ramirez Cesar Augusto
# Fecha: 2026-04-24
# Descripción:
# Defs de server y cliente en un solo codigo

import socket, threading

Host = '0.0.0.0'
Port = 5000 

def iniciar_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((Host, Port)) 
    server.listen(1)
    print(f"(Servidor) Esperando coneccion con el cliente...")

    con, addr = server.accept()
    print(f"(Servidor) Conectado desde {addr}")

    def recv():
        while True:
            try:
                data = con.recv(1024).decode()
                if not data:
                    break
                print(f"\n(Cliente) {data}")
            except:
                break

    threading.Thread(target=recv, daemon=True).start()
    while True:
        msg = input()
        con.send(msg.encode())

def iniciar_cliente():
    cliente = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
    cliente.connect(('192.168.100.3', 5000))
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

if __name__ == "__main__":
    modo = input("Eres? (servidor/cliente)").strip().lower()

    if modo == "servidor":
        iniciar_server()
    elif modo == "cliente":
        iniciar_cliente()
    else:
        print("Error")