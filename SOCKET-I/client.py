# client logic

import socket # for socket methods

HOST = "172.16.8.85"  # the server host (here both client and server are same - loopback)
PORT = 65432  #port used by server - same

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST,PORT))
    s.sendall(b"Hello, World")
    data = s.recv(1024)

    print("Recieved",data)
