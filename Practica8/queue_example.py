from multiprocessing import Queue, Process

def square(numbers, queue):
    for i in numbers:
        queue.put(i*i)

def make_negative(numbers, queue):
    for i in numbers:
        queue.put(-1*i)

def cube(numbers, queue):
    for i in numbers:
        queue.put(i*i*i)

def add_one(numbers, queue):
    for i in numbers:
        queue.put(i+1)

q = Queue()
numbers = range(1,8)

p1 = Process(target=square, args=(numbers, q))
p2 = Process(target=make_negative, args=(numbers,q))
p3 = Process(target=cube, args=(numbers,q))
p4 = Process(target=add_one, args=(numbers,q))

p1.start()
p2.start()
p3.start()
p4.start()

p1.join()
p2.join()
p3.join()
p4.join()

while not q.empty():
    print(q.get())