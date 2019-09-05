import socket
th="0.0.0.0"
tp=9999
client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect((th,tp))
a=client.sendall(b"GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n")
print(client.recv(4096))
print("\n")
print(a)