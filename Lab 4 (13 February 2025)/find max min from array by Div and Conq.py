import time
import random
import matplotlib.pyplot as p

def find_max_min(arr, low, high):
    if low == high:
        return arr[low], arr[low]
    elif high == low + 1:
        return (max(arr[low], arr[high]), min(arr[low], arr[high]))
    else:
        mid = (low + high) // 2
        max1, min1 = find_max_min(arr, low, mid)
        max2, min2 = find_max_min(arr, mid+1, high)
        return max(max1, max2), min(min1, min2)

sizes = list(range(1000, 11000, 1000))
times = []

for n in sizes:
    arr = [random.randint(1, 100000) for _ in range(n)]
    start = time.time()
    find_max_min(arr, 0, n - 1)
    end = time.time()
    times.append(end - start)

p.plot(sizes, times, marker='o', label='Divide and Conquer Max-Min (O(n))')
p.xlabel('Array Size (n)')
p.ylabel('Execution Time (seconds)')
p.title('Time Complexity of Max-Min using Divide and Conquer')
p.grid(True)
p.legend()
p.show()