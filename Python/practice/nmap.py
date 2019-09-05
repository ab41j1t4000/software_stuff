import socket
import subprocess
import sys
from datetime import datetime

target_name = input("Enter the address of the server to scan: ")
sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
target_ip = socket.gethostbyname(target_name)
#subprocess('clear',shell = True)

try:
    for port in (1,81):
        result = sock.connect_ex((target_ip,port))
        if (result == 0):
            print("Port {} : Open",port)
except:
    if KeyboardInterrupt:
        print("\nScan stopped")
        sys.exit()
    if sock.error:
        print("Cannot connect to host\nQuitting.....\n")
        sys.exit()

