import time
import random
import matplotlib.pyplot as plt

def matrix_chain_order(p, n):
    m = [[0] * n for _ in range(n)]
    for L in range(2, n):
        for i in range(1, n - L + 1):
            j = i + L - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]
                if cost < m[i][j]:
                    m[i][j] = cost
    return m[1][n - 1]

def measure_execution_time():
    sizes = list(range(5, 101, 5))
    times = []

    for n in sizes:
        p = [random.randint(10, 100) for _ in range(n + 1)]
        start = time.time()
        matrix_chain_order(p, n + 1)
        end = time.time()
        times.append(end - start)

    return sizes, times

sizes, times = measure_execution_time()

plt.plot(sizes, times, marker='o', color='green')
plt.title("Time Complexity of Matrix Chain Multiplication (DP)")
plt.xlabel("Number of Matrices (n)")
plt.ylabel("Execution Time (seconds)")
plt.grid(True)
plt.show()