import socket
import sys
from _thread import *

host = ''
port = 5555
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

try:
    s.bind((host,port))
except socket.error as e:
    print(str(e))

s.listen(5)
print('Oczekuje nia polaczie')

def threaded_client(conn):
    #conn.send(str.encode('Witam, wprowadz swoja wiadomosc'))

    while True:
        data = conn.recv(2048)
        replay = 'Odpowiedz serwera: '+data.decode()
        if not data:
            break
        conn.sendall(str.encode('OK'))
    conn.close()

while True:
    conn, addr = s.accept()
    print('connected to: '+addr[0]+str(addr[1]))
    start_new_thread(threaded_client,(conn,))