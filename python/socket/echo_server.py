import socket
import _thread
import json

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('0.0.0.0', 8888)
print('starting up on {} port {}'.format(*server_address))
sock.bind(server_address)
sock.listen(10)


def capture_client(connection):
    response = b''
    while True:
        try:
            data = connection.recv(2048)
            response += data
            connection.sendall('Potwierdzam'.encode('utf-8'))
            if data:
                print(json.loads(response.decode('utf-8')))
            else:
                print("Pusto elo nara")
                connection.close()
                break
        except:
            print('cos sie zesralo')
            connection.close()
            break


while True:
    try:
        print('waiting for a connection')
        connection, client_address = sock.accept()
        print('connection from', client_address)
        _thread.start_new_thread( capture_client, (connection,))
    except:
        connection.close()
        sock.close()


