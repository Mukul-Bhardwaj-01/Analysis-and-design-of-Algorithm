import time
import matplotlib.pyplot as plt

def is_safe(board, row, col, n):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row+1, n), range(col-1, -1, -1)):
        if board[i][j] == 1:
            return False
    return True

def solve(board, col, n):
    if col >= n:
        return True
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1
            if solve(board, col + 1, n):
                return True
            board[i][col] = 0
    return False

def n_queens(n):
    board = [[0]*n for _ in range(n)]
    return solve(board, 0, n)

def measure_execution_time():
    sizes = list(range(4, 16))  # n from 4 to 15
    times = []
    for n in sizes:
        start = time.time()
        n_queens(n)
        end = time.time()
        times.append(end - start)
    return sizes, times

sizes, times = measure_execution_time()

plt.plot(sizes, times, marker='o', color='purple')
plt.title("Time Complexity of N-Queens (Backtracking)")
plt.xlabel("Number of Queens (n)")
plt.ylabel("Execution Time (seconds)")
plt.grid(True)
plt.show()