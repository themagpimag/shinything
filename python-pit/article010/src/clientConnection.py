# In the example this script is typed
import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(("192.168.1.3", 20000)) # The IP address of the server machine
sock.close()
