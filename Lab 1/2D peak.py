import time
import random
import matplotlib.pyplot as p

def findPeak2D(Arr, Peaks, m,n):
    for i in range(0,m):
        for j in range(0,n):
            isPeak=True
            if i > 0 and Arr[i][j] <= Arr[i - 1][j]:
                isPeak = False
            
            if i < m - 1 and Arr[i][j] <= Arr[i + 1][j]:
                isPeak = False
            
            if j > 0 and Arr[i][j] <= Arr[i][j - 1]:
                isPeak = False
            
            if j < n - 1 and Arr[i][j] <= Arr[i][j + 1]:
                isPeak = False

            if isPeak:
                Peaks[i][j] = 1

mn_sizes=[10,20,30,40,50,60]
TimeC = []
for size in mn_sizes:
    rows=columns=size
    Arr= [[random.randint(2,1000000) for _ in range(rows)] for _ in range(columns)]
    Peaks= [[0 for _ in range(rows)] for _ in range(columns)]
    start= time.time()
    findPeak2D(Arr,Peaks,rows,columns)
    end = time.time()
    timeTaken = end - start
    TimeC.append(timeTaken)

p.figure(figsize=(10,5))
p.xlabel("Number of rows or columns(m or n)")
p.ylabel("Time taken(s)")
p.title("Time Complexity 2D peak")
p.plot(mn_sizes, TimeC, marker="o", linestyle="dashed", label="Time Complexity curve for 2D peak")
p.legend()
p.grid(True)
p.show()