from argparse import ArgumentParser
import asyncio
from sys import stdin, exit, argv

client_name = argv[2]

class tcpclient:
    def __init__(self, reader, writer, client_name):
        self.writer = writer
        self.reader = reader
        self.client_name = client_name

    @asyncio.coroutine
    def recv(self):
        return (yield from self.reader.read(100)).decode()

    @asyncio.coroutine
    def send(self, msg):
        self.writer.write(msg.encode())


@asyncio.coroutine
def chat_recv(socket):
    while True:
        echo = yield from socket.recv()
        if echo is None: break
        print("%s" % echo)


@asyncio.coroutine
def chat_send(socket):
    print('Write A Command: ')
    reader = asyncio.StreamReader()
    yield from asyncio.get_event_loop().connect_read_pipe(lambda: asyncio.StreamReaderProtocol(reader), stdin)
    while True:
        command = (yield from reader.readline()).decode('utf-8').strip('\r\n')
        command_parts = command.split()
        if command_parts[0] == 'join' or command_parts[0] == 'leave':
            if len(command_parts) != 2:
                print('Error in command')
            else:
                try:
                    int(command_parts[1])
                    command = command + " " + client_name
                    yield from socket.send(command)
                except:
                    print('Enter a number for groupID')
        elif command_parts[0] == 'send':
            if len(command_parts) < 3:
                print('Error in command')
            else:
                try:
                    int(command_parts[1])
                    command = command + " " + client_name
                    yield from socket.send(command)
                except:
                    print('Enter a number for groupID')
        elif command_parts[0] == 'quit':
            exit(0)
        else:
            print('Error in command')


@asyncio.coroutine
def chat(loop, host, port):
    reader, writer = yield from asyncio.open_connection(host, port, loop=loop)
    client = tcpclient(reader, writer, client_name)
    tasks = [chat_recv(client), chat_send(client)]
    yield from asyncio.wait(tasks)


parser = ArgumentParser(description='Chat Client Python3 Script')
parser.add_argument('-i', dest='ip', type=str, help='Host IP Address - Optional [Default=127.0.0.1]',
                    default='127.0.0.1')
parser.add_argument('-p', dest='port', type=int, help='Host Port Number - Optional [Default=8888]', default=8888)
parser.add_argument('-n', dest='name', type=str, help='Name For Client', default="Unknown")
args = parser.parse_args()
loop = asyncio.get_event_loop()
loop.run_until_complete(chat(loop, args.ip, args.port))
loop.close()

