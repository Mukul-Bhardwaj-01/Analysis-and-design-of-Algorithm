import time
import random
import matplotlib.pyplot as plt

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def measure_time(arr):
    start_time = time.time()
    merge_sort(arr)
    end_time = time.time()
    return end_time - start_time

sizes = [100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
times = [measure_time(random.sample(range(size), size)) for size in sizes]

plt.figure(figsize=(10, 6))
plt.plot(sizes, times, label="Merge Sort (O(n log n))", marker="o", linestyle="dashed", color="blue")

plt.xlabel("Input Size (n)")
plt.ylabel("Time Taken (seconds)")
plt.title("Merge Sort Time Complexity Analysis")
plt.legend()
plt.grid()
plt.show()