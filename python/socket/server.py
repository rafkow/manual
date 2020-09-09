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
	conn.send(str.encode('Witam, wprowadz swoja wiadomosc'))
	conn.recv(2048)
	while True:
		data = conn.recv(2048)
		if data:
			conn.send(str(data))
		else:
			conn.send(str.encode('Brak danych wejsciowych'))
	conn.close()

while True:
	try:
		conn, addr = s.accept()
		print('connected to: {}:{} '.format(addr[0],addr[1]))
		start_new_thread(threaded_client,(conn,))
	except:
		print('cos sie zesralo')
		