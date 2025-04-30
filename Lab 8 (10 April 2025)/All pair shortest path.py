import time
import matplotlib.pyplot as plt
import random

def floyd_warshall(graph):
    V = len(graph)
    dist = [row[:] for row in graph]
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist

def generate_random_graph(V):
    graph = [[float('inf')] * V for _ in range(V)]
    for i in range(V):
        graph[i][i] = 0
    for i in range(V):
        for j in range(i + 1, V):
            weight = random.randint(1, 10)
            graph[i][j] = graph[j][i] = weight
    return graph

def measure_execution_time():
    sizes = list(range(2, 21))
    times = []
    for V in sizes:
        graph = generate_random_graph(V)
        start_time = time.time()
        floyd_warshall(graph)
        end_time = time.time()
        times.append(end_time - start_time)
    return sizes, times

sizes, times = measure_execution_time()

plt.plot(sizes, times, marker='o', linestyle='-', color='b')
plt.xlabel('Number of Vertices (V)')
plt.ylabel('Execution Time (Seconds)')
plt.title('Time Complexity of Floyd-Warshall Algorithm')
plt.grid(True)
plt.show()