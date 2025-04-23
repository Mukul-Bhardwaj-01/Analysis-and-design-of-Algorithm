import numpy as np
import time
import matplotlib.pyplot as p

def divide_and_conquer_multiply(A, B):
    n = len(A)
    if n == 1:
        return [[A[0][0] * B[0][0]]]
    else:
        mid = n // 2
        A11 = A[:mid, :mid]
        A12 = A[:mid, mid:]
        A21 = A[mid:, :mid]
        A22 = A[mid:, mid:]

        B11 = B[:mid, :mid]
        B12 = B[:mid, mid:]
        B21 = B[mid:, :mid]
        B22 = B[mid:, mid:]

        M1 = divide_and_conquer_multiply(A11, B11)
        M2 = divide_and_conquer_multiply(A12, B21)
        M3 = divide_and_conquer_multiply(A11, B12)
        M4 = divide_and_conquer_multiply(A12, B22)
        M5 = divide_and_conquer_multiply(A21, B11)
        M6 = divide_and_conquer_multiply(A22, B21)
        M7 = divide_and_conquer_multiply(A21, B12)
        M8 = divide_and_conquer_multiply(A22, B22)

        C11 = np.add(M1, M2)
        C12 = np.add(M3, M4)
        C21 = np.add(M5, M6)
        C22 = np.add(M7, M8)

        top = np.hstack((C11, C12))
        bottom = np.hstack((C21, C22))
        return np.vstack((top, bottom))

sizes = [2**i for i in range(1, 8)]
times = []

for n in sizes:
    A = np.random.randint(0, 10, (n, n))
    B = np.random.randint(0, 10, (n, n))
    start = time.time()
    divide_and_conquer_multiply(A, B)
    end = time.time()
    times.append(end - start)

p.plot(sizes, times, marker='o', label='Divide & Conquer Matrix Multiplication (O(n³))')
p.xlabel('Matrix Size (n x n)')
p.ylabel('Execution Time (seconds)')
p.title('Time Complexity of Divide and Conquer Matrix Multiplication')
p.grid(True)
p.legend()
p.show()