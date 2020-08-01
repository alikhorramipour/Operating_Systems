import threading
import time

Lock = threading.Lock()

counter = 0

def say_hello(n):
	global counter
	for i in range(0, 10):
		Lock.acquire()
		counter+=1
		print(f'Thread {n}: {i} -> {counter}')
		Lock.release()
		time.sleep(.5)

def read(n):
	global counter

	for i in range(0, 5):
		Lock.acquire()
		print(f'Thread_reader {n}: {i} -> {counter}')
		Lock.release()
		time.sleep(.5)
		
	

if __name__ == '__main__':
	t1 = threading.Thread(target = say_hello, args=(1, ))
	t2 = threading.Thread(target = read, args=(1, ))
	t3 = threading.Thread(target = read, args=(2, ))

	t2.start()
	t1.start()
	t3.start()