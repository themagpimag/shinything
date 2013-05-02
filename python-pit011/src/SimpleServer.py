import socket
import threading

class SimpleServer:
  def __init__(self,host,port):
    self.host = host
    self.port = port
    self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    self.sock.settimeout(None) 
    self.client_sockets = []    
    
  def initialise(self):
    try:
      self.sock.bind((self.host, self.port))
    except socket.error:
      return
            
    self.sock.listen(5)
    self.server_thread = threading.Thread(target=self.serve_forever)
    self.server_thread.setDaemon(True)
    self.server_thread.start()
    print "Server running on %s and listening on %d" % (self.host, self.port)

  def serve_forever(self):
    try:
      request, client_address = self.sock.accept()
    except socket.error:
      return
    
    self.client_sockets.append(request)
    print "Received connection from ", client_address
