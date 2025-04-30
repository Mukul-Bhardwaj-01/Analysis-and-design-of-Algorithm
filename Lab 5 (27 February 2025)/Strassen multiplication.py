import numpy as np
import time
import matplotlib.pyplot as plt

def standard_multiply(A, B):
    return np.dot(A, B)

def strassen(A, B):
    n = len(A)
    if n == 1:
        return A * B

    mid = n // 2

    A11 = A[:mid, :mid]
    A12 = A[:mid, mid:]
    A21 = A[mid:, :mid]
    A22 = A[mid:, mid:]

    B11 = B[:mid, :mid]
    B12 = B[:mid, mid:]
    B21 = B[mid:, :mid]
    B22 = B[mid:, mid:]

    M1 = strassen(A11 + A22, B11 + B22)
    M2 = strassen(A21 + A22, B11)
    M3 = strassen(A11, B12 - B22)
    M4 = strassen(A22, B21 - B11)
    M5 = strassen(A11 + A12, B22)
    M6 = strassen(A21 - A11, B11 + B12)
    M7 = strassen(A12 - A22, B21 + B22)

    C11 = M1 + M4 - M5 + M7
    C12 = M3 + M5
    C21 = M2 + M4
    C22 = M1 - M2 + M3 + M6

    top = np.hstack((C11, C12))
    bottom = np.hstack((C21, C22))
    return np.vstack((top, bottom))

sizes = [2**i for i in range(1, 8)]
standard_times = []
strassen_times = []

for size in sizes:
    A = np.random.randint(0, 10, size=(size, size))
    B = np.random.randint(0, 10, size=(size, size))

    start = time.time()
    standard_multiply(A, B)
    end = time.time()
    standard_times.append(end - start)

    start = time.time()
    strassen(A, B)
    end = time.time()
    strassen_times.append(end - start)

plt.plot(sizes, standard_times, label="Standard Multiplication", marker='o')
plt.plot(sizes, strassen_times, label="Strassen's Multiplication", marker='s')
plt.xlabel('Matrix Size (n x n)')
plt.ylabel('Time (seconds)')
plt.title("Time Complexity Comparison")
plt.legend()
plt.grid(True)
plt.show()