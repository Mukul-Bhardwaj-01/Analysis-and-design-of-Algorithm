import time
import random
import matplotlib.pyplot as plt

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def measure_time(arr):
    start_time = time.time()
    insertion_sort(arr)
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
plt.plot(sizes, best_case_times, label="Best Case (O(n))", marker="o", linestyle="dashed", color="green")
plt.plot(sizes, average_case_times, label="Average Case (O(n²))", marker="s", linestyle="dashed", color="blue")
plt.plot(sizes, worst_case_times, label="Worst Case (O(n²))", marker="^", linestyle="dashed", color="red")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Insertion Sort Time Complexity Analysis")
plt.legend()
plt.grid()
plt.show()