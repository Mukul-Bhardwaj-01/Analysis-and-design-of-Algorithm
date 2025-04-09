import time
import random
import matplotlib.pyplot as p

def heapify(arr,n,i):
    largest = i
    left = 2*i + 1
    right = 2*i + 2
    if n>left and arr[left]>arr[largest]:
        largest=left
    if n>right and arr[right]>arr[largest]:
        largest=right

    if largest!=i:
        arr[i],arr[largest]=arr[largest],arr[i]
        heapify(arr,n,largest)

def heapsort(arr,n):
    for i in range(n//2-1,-1,-1):
        heapify(arr,n,i)
    
    for i in range(n-1,0,-1):
        arr[0],arr[i]=arr[i],arr[0]
        heapify(arr,i,0)

sizes = [10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,1000,1500,2000,2500,3000]
timeC = []
for size in sizes:
    arr= [random.randint(1,200000) for _ in range(size)]
    start = time.time()
    heapsort(arr, size)
    end = time.time()
    timeTaken = end - start
    timeC.append(timeTaken)

p.figure(figsize=(10,5))
p.plot(sizes, timeC, marker="o", linestyle="dotted", label="TC plot for heap sort")
p.xlabel("Size(n) or array")
p.ylabel("Time taken to sort")
p.legend()
p.grid(True)
p.show()

