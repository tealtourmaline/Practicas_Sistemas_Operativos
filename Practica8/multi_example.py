import multiprocessing
import time

def contar(num):
    cnt = 0
    for _ in range(num):
        cnt +=1
        time.sleep(0.1)
    print('contador terminó')

#ejecución serial
start = time.time()
contar(15)
contar(20)
contar(10)
contar(50)
print('tiempo de ejecución serial: ', time.time()-start)                 

#ejecución con multiprocesamiento
start = time.time()
p1 = multiprocessing.Process(target=contar, args=[15])
p2 = multiprocessing.Process(target=contar, args=[20])
p3 = multiprocessing.Process(target=contar, args=[10])
p4 = multiprocessing.Process(target=contar, args=[50])

p1.start()
p2.start()
p3.start()
p4.start()

#esperamos a que terminen las tareas
p1.join()
p2.join()
p3.join()
p4.join()
 
print('tiempo de ejecución paralelo: ', time.time()-start)                                                                                           