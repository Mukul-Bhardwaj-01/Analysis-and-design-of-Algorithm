import time
import random
import matplotlib.pyplot as p

def findPeak(arr1, arr2, n):
    if n==1:
        arr2[0]=1

    else:
        for i in range(1,n-1):
            if arr1[i]>arr1[i-1] and arr1[i]>arr1[i+1]:
                arr2[i]=1
            
        if arr1[0]>arr1[1]:
            arr2[0]=1
        if arr1[n-1]>arr1[n-2]:
            arr2[n-1]=1

timeC=[]
sizes = [10,100,1000,10000,100000]
for size in sizes:
    arr1= [random.randint(1,100000) for _ in range(size)]
    arr2 = [0 for _ in range(size)]

    start = time.time()
    findPeak(arr1, arr2, size)
    end = time.time()
    timeTaken = end - start
    timeC.append(timeTaken)

p.figure(figsize=(10,5))
p.plot(sizes, timeC, marker="o", linestyle="-", label = "Time Complexity for 1D peak", color="red")
p.xlabel("Size(n) of array")
p.ylabel("Time taken(s)")
p.title("TC plot for 1D peak")
p.legend()
p.grid(True)
p.show()