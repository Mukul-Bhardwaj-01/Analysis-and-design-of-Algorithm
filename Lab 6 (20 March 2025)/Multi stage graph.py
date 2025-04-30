import time
import matplotlib.pyplot as plt
import random

def min_cost_multi_stage_graph(graph, start, end):
    n = len(graph)
    dp = [float('inf')] * n
    path = [-1] * n
    dp[end] = 0
    for stage in range(n - 2, -1, -1):
        for next_stage in range(stage + 1, n):
            if graph[stage][next_stage] != 0:
                cost = graph[stage][next_stage] + dp[next_stage]
                if cost < dp[stage]:
                    dp[stage] = cost
                    path[stage] = next_stage
    min_cost = dp[start]
    path_taken = [start]
    current_stage = start
    while path[current_stage] != -1:
        path_taken.append(path[current_stage])
        current_stage = path[current_stage]
    return min_cost, path_taken

def generate_graph(n):
    graph = [[0] * n for _ in range(n)]
    for i in range(n - 1):
        for j in range(i + 1, n):
            if random.random() < 0.5:
                graph[i][j] = random.randint(1, 100)
    return graph

def measure_execution_time():
    sizes = list(range(2, 21))
    times = []
    for n in sizes:
        graph = generate_graph(n)
        start_time = time.time()
        min_cost_multi_stage_graph(graph, 0, n - 1)  # Assuming start = 0 and end = n - 1
        end_time = time.time()
        times.append(end_time - start_time)
    return sizes, times

sizes, times = measure_execution_time()

plt.plot(sizes, times, marker='o', linestyle='-', color='b')
plt.xlabel('Number of Nodes (Stages)')
plt.ylabel('Execution Time (Seconds)')
plt.title('Time Complexity of Multi-Stage Graph (Dynamic Programming)')
plt.grid(True)
plt.show()