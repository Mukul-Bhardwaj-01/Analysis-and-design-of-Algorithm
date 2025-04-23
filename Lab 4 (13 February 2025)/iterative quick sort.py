import time
import random
import matplotlib.pyplot as p

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i + 1

def iterative_quick_sort(arr):
    stack = [(0, len(arr) - 1)]
    
    while stack:
        low, high = stack.pop()
        if low < high:
            pi = partition(arr, low, high)
            stack.append((low, pi - 1))
            stack.append((pi + 1, high))

sizes = list(range(1000, 11000, 1000))
times = []

for size in sizes:
    arr = [random.randint(1, 100000) for _ in range(size)]
    start = time.time()
    iterative_quick_sort(arr)
    end = time.time()
    times.append(end - start)

p.plot(sizes, times, marker='o', label='Iterative Quick Sort (Avg: O(n log n))')
p.xlabel('Array Size (n)')
p.ylabel('Execution Time (seconds)')
p.title('Time Complexity of Iterative Quick Sort')
p.grid(True)
p.legend()
p.show()