
import socket

HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
PORT = 65432        # Port to listen on (non-privileged ports are > 1023)

group=["friend","home"]

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            if data!=None:
                print(data.decode())
            # conn.sendall(b'ata')



#
# import socket
#
# HOST = '127.0.0.1'  # Standard loopback interface address (localhost)
# PORT = 65432        # Port to listen on (non-privileged ports are > 1023)
#
# group=["friend","home"]
#
#
# with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
#     s.bind((HOST, PORT))
#     s.listen()
#     conn, addr = s.accept()
#     with conn:
#         print('Connected by', addr)
#         while True:
#             data = conn.recv(1024)
#             if data!=None:
#                  # groupName=data.decode().split(' ')[1]
#                  print(data.decode())
#                 # command=data.decode().split(' ')[0]
#                 # if command=="join":
#                # groupName=data.decode().split(' ')[1]
#                # print(groupName)
#                    # print('user :',addr,' join the group :',groupName)
#
#
#             # conn.sendall(b'ata')
