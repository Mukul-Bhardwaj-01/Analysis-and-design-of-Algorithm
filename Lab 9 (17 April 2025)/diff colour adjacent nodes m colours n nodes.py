import time
import random
import matplotlib.pyplot as plt

def is_safe(node, graph, color, c):
    for i in range(len(graph)):
        if graph[node][i] == 1 and color[i] == c:
            return False
    return True

def solve(node, graph, m, color):
    if node == len(graph):
        return True
    for c in range(1, m + 1):
        if is_safe(node, graph, color, c):
            color[node] = c
            if solve(node + 1, graph, m, color):
                return True
            color[node] = 0
    return False

def graph_coloring(graph, m):
    n = len(graph)
    color = [0] * n
    return solve(0, graph, m, color)

def generate_random_graph(n, edge_prob=0.5):
    graph = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            if random.random() < edge_prob:
                graph[i][j] = graph[j][i] = 1
    return graph

def measure_execution_time(m=3):
    sizes = list(range(2, 13))
    times = []
    for n in sizes:
        graph = generate_random_graph(n, edge_prob=0.5)
        start = time.time()
        graph_coloring(graph, m)
        end = time.time()
        times.append(end - start)
    return sizes, times

sizes, times = measure_execution_time()

plt.plot(sizes, times, marker='o', color='red')
plt.title("Time Complexity of M-Coloring (Backtracking)")
plt.xlabel("Number of Nodes (n)")
plt.ylabel("Execution Time (seconds)")
plt.grid(True)
plt.show()