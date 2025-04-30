import time
import matplotlib.pyplot as plt
import random

def knapsack(val, wt, W, n):
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for w in range(1, W + 1):
            if wt[i - 1] <= w:
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]
    return dp[n][W]

def measure_execution_time():
    sizes = list(range(10, 201, 10))
    times = []
    W = 100

    for n in sizes:
        val = [random.randint(1, 100) for _ in range(n)]
        wt = [random.randint(1, 100) for _ in range(n)]
        start_time = time.time()
        knapsack(val, wt, W, n)
        end_time = time.time()
        times.append(end_time - start_time)

    return sizes, times

sizes, times = measure_execution_time()

plt.plot(sizes, times, marker='o', color='blue')
plt.title("Time Complexity of 0/1 Knapsack (DP)(O(n * W))")
plt.xlabel("Number of Items (n)")
plt.ylabel("Execution Time (seconds)")
plt.grid(True)
plt.show()