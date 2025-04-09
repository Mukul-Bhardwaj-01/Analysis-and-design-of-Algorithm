import time
import random
import matplotlib.pyplot as p

def bubbleSort(arr):
    n=len(arr)
    for i in range(n):
        swapped=False
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
                swapped=True
        if not swapped:
            break

def measureTime(arr):
    start_time=time.time()
    bubbleSort(arr)
    end_time=time.time()
    return end_time - start_time

sizes=[50,500,5000,50000,500000]
timeC=[]

for size in sizes:
    arr = [random.randint(1,1000000) for _ in range(size)]
    timeC.append(measureTime(arr))

p.figure(figsize=(10,5))
p.plot(sizes, timeC, marker="o", linestyle="-", label="Bubble Sort TC curve")
p.xlabel("Array sizes(n)")
p.ylabel("Time taken(s)")
p.title("Bubble Sort")
p.legend()
p.grid(True)
p.show