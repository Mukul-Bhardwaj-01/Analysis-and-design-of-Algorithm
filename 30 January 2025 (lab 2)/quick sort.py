import time
import random
import matplotlib.pyplot as plt

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def measure_time(arr):
    start_time = time.time()
    quick_sort(arr)
    end_time = time.time()
    return end_time - start_time

sizes = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
times = [measure_time(random.sample(range(size), size)) for size in sizes]

plt.figure(figsize=(10, 6))
plt.plot(sizes, times, label="Quick Sort (O(n log n))", marker="o", linestyle="dashed", color="purple")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Quick Sort Time Complexity Analysis")
plt.legend()
plt.grid()
plt.show()