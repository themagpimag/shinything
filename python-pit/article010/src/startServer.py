# In the example this script is typed
from SimpleServer import SimpleServer
import socket
server = SimpleServer(socket.getfqdn(), 20000)
server.initialise()
