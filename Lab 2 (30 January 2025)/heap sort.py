import time
import random
import matplotlib.pyplot as plt

def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

def measure_time(arr):
    start_time = time.time()
    heap_sort(arr)
    end_time = time.time()
    return end_time - start_time

sizes = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
best_case_times = []
average_case_times = []
worst_case_times = []

for size in sizes:
    best_case_arr = list(range(size))
    average_case_arr = random.sample(range(size), size)
    worst_case_arr = list(range(size, 0, -1))

    best_case_times.append(measure_time(best_case_arr))
    average_case_times.append(measure_time(average_case_arr))
    worst_case_times.append(measure_time(worst_case_arr))

plt.figure(figsize=(10, 6))
plt.plot(sizes, best_case_times, label="Best Case (O(n log n))", marker="o", linestyle="dashed", color="green")
plt.plot(sizes, average_case_times, label="Average Case (O(n log n))", marker="s", linestyle="dashed", color="blue")
plt.plot(sizes, worst_case_times, label="Worst Case (O(n log n))", marker="^", linestyle="dashed", color="red")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Heap Sort Time Complexity Analysis")
plt.legend()
plt.grid()
plt.show()