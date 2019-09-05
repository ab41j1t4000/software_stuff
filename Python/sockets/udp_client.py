import socket
th='127.0.0.1'
tp=80
client=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
message="AAABBBCCC"
client.sendto(message.encode('utf-8'),(th,tp))
data,addr=client.recvfrom(4096)
print(data)
print("\n")
print(addr)