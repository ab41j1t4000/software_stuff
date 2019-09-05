import socket
SOCKET = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
cmd = 'GET http://www.google.com/ HTTP/1.0\n\n'.encode()
SOCKET.connect(('www.google.com',80))
SOCKET.send(cmd)

while True:
    data = SOCKET.recv(512)
    if (len(data)<1):
        break
    print(data.decode())
SOCKET.close()