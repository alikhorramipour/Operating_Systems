from argparse import ArgumentParser
import asyncio

number_of_groups = 3
clients = []
groups = [[] for i in range(number_of_groups)]


class ChatServer(asyncio.Protocol):

    def __init__(self):
        self.transport = None
        self.peername = None

    def connection_made(self, transport):
        self.transport = transport
        self.peername = transport.get_extra_info("peername")
        print("connection_made: {}".format(self.peername))
        clients.append(self)

    def data_received(self, data):
        msg = data.decode()
        print("data_received: {}".format(msg))
        msg_parts = msg.split()
        if msg_parts[0] == 'join':
            groupID = int(msg_parts[1])
            if 0 <= groupID < number_of_groups:
                groups[groupID].append(self)
            else:
                self.transport.write('No such group!'.encode())
        elif msg_parts[0] == 'send':
            groupID = int(msg_parts[1])
            if 0 <= groupID < number_of_groups:
                if self in groups[groupID]:
                    for client in groups[groupID]:
                        client.transport.write("(Group #{}) -> {}: {}".format(groupID, msg_parts[len(msg_parts)-1]," ".join(msg_parts[2:len(msg_parts)-1])).encode())
                else:
                    self.transport.write('You are not in the group!'.encode())
            else:
                self.transport.write('No such group!'.encode())
        elif msg_parts[0] == 'leave':
            groupID = int(msg_parts[1])
            if 0 <= groupID < number_of_groups:
                groups[groupID].remove(self)
            #elif command_parts[0] == "leave" and not(groups[groupID].contains(self)):
             #   self.transport.write(('You are not in group ', groupID, '!').encode())
            else:
                self.transport.write('No such group!'.encode())


    def connection_lost(self, ex):
        print("connection_lost: {}".format(self.peername))
        clients.remove(self)


parser = ArgumentParser(description='Chat Server Python3 Script')
parser.add_argument('-i', dest='ip', type=str, help='Host IP Address - Optional [Default=127.0.0.1]',
                    default='127.0.0.1')
parser.add_argument('-p', dest='port', type=int, help='Host Port Number - Optional [Default=8888]', default=8888)
args = parser.parse_args()
loop = asyncio.get_event_loop()
coro = loop.create_server(ChatServer, args.ip, args.port)
server = loop.run_until_complete(coro)
print('Serving on {}'.format(server.sockets[0].getsockname()))
try:
    loop.run_forever()
except KeyboardInterrupt:
    pass
server.close()
loop.run_until_complete(server.wait_closed())
loop.close()
