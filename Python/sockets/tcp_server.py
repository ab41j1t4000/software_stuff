import socket
import threading
server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
bip="0.0.0.0"
bport=9999
server.bind((bip,bport))
server.listen(5)
print("[*] Listening on %s:%d" % (bip,bport))
def handle_client(client_socket):
    request=client_socket.recv(1024)
    print("[*] Recieved: %s" % request)
    client_socket.send(b"ACK!")
    client_socket.close()
while True:
    client,addr =server.accept()
    print("[*] Accepted connection from: %s:%d" % (addr[0],addr[1]))
    client_handler=threading.Thread(target=handle_client,args=(client,))
    client_handler.start()
