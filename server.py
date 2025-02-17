import sys
import socket  
  
def get_file_hex_content(filename):  
    with open(filename, 'rb') as file:  
        return file.read()
  
def server_loop(host, port):  
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  
    server_socket.bind((host, port))  
    server_socket.listen(1)  
  
    print(f"server listening {host}:{port}...")  
  
    while True:  
        client_socket, client_address = server_socket.accept()  
        print(f"request in {client_address}")  
  
        try:  
            #data = client_socket.recv(1024).decode()  
             
                hex_content = get_file_hex_content('')  
                client_socket.sendall(hex_content)  
                print(f"send data {client_address}")  
            #else:  
                #client_socket.sendall("Invalid request.".encode())  
  
        except ConnectionResetError:  
            print(f"Client {client_address} disconnected unexpectedly")  
  
        finally:  
            client_socket.close()  
  
if __name__ == '__main__':  
   


 server_loop('localhost', 1200)