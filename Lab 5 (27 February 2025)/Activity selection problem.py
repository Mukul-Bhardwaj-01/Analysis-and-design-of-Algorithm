import time
import random
import matplotlib.pyplot as p

def activity_selection(start, end, n):
    activities = sorted(zip(start, end), key=lambda x: x[1])  # Sort by finish time
    selected = [activities[0]]
    last_end = activities[0][1]

    for i in range(1, n):
        if activities[i][0] >= last_end:
            selected.append(activities[i])
            last_end = activities[i][1]
    return selected

sizes = [10, 100, 1000, 2000, 5000, 10000]
times = []

for n in sizes:
    start_times = [random.randint(0, 1000) for _ in range(n)]
    end_times = [s + random.randint(1, 100) for s in start_times]

    start_time = time.time()
    activity_selection(start_times, end_times, n)
    end_time = time.time()

    times.append(end_time - start_time)

import math
k = times[0] / (sizes[0] * math.log2(sizes[0]))
onlogn = [k * n * math.log2(n) for n in sizes]

p.figure(figsize=(10, 5))
p.plot(sizes, times, marker="o", label="Measured Time", color="red")
p.plot(sizes, onlogn, linestyle="--", label="O(n log n) Reference", color="blue")

p.xlabel("Number of Activities (n)")
p.ylabel("Time (seconds)")
p.title("Activity Selection: Time Complexity vs O(n log n)")
p.legend()
p.grid(True)
p.show()