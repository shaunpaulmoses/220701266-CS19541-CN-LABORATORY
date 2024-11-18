# client logic

import socket # for socket methods

HOST = "127.0.0.1"  # the server host (here both client and server are same - loopback)
PORT = 65431  #port used by server - same


    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        while(True):
        my_message = input("enter your message: ")
        if not data:
            print("Over and Out")
            break
        s.connect((HOST,PORT))
        s.sendall(my_message.encode())
        data = s.recv(1024)
        print("Recieved",data)
        if(data=="bye"):
            break
        s.close()     
