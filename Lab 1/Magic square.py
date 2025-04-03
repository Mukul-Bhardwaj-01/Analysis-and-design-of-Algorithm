import time
import matplotlib.pyplot as plt

def magicSquare(n, matrix):
    i, j = 0, n // 2
    for num in range(1, n * n + 1):
        matrix[i][j] = num
        new_i = (i - 1 + n) % n
        new_j = (j + 1) % n

        if matrix[new_i][new_j] != 0:
            i = (i + 1) % n
        else:
            i, j = new_i, new_j

mn_sizes = [1, 5, 9, 21, 51, 101]
timeC = []

for size in mn_sizes:
    arr = [[0 for _ in range(size)] for _ in range(size)]
    start = time.time()
    magicSquare(size, arr)
    end = time.time()
    timeC.append(end - start)

plt.figure(figsize=(10, 5))
plt.plot(mn_sizes, timeC, marker="^", linestyle="dotted", label="Time Complexity for Magic Square")
plt.xlabel("Size of Magic Square (n)")
plt.ylabel("Time Taken (seconds)")
plt.legend()
plt.grid(True)
plt.show()