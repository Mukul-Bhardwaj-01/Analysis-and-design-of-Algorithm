import random
import heapq
import time
import matplotlib.pyplot as p
import math

def dijkstra(graph, source, V):
    dist = [float('inf')] * V
    dist[source] = 0
    pq = [(0, source)]  # (distance, vertex)

    while pq:
        current_dist, u = heapq.heappop(pq)

        if current_dist > dist[u]:
            continue

        for v, weight in graph[u]:
            if dist[v] > current_dist + weight:
                dist[v] = current_dist + weight
                heapq.heappush(pq, (dist[v], v))
    return dist

def generate_graph(V, avg_degree=2):
    graph = [[] for _ in range(V)]
    for u in range(V):
        for _ in range(avg_degree):
            v = random.randint(0, V - 1)
            while v == u:
                v = random.randint(0, V - 1)
            weight = random.randint(1, 10)
            graph[u].append((v, weight))
    return graph

sizes = [100, 200, 500, 1000, 2000, 3000]
times = []

for V in sizes:
    graph = generate_graph(V)
    start_time = time.time()
    dijkstra(graph, 0, V)
    end_time = time.time()
    times.append(end_time - start_time)

k = times[0] / ((sizes[0] * math.log2(sizes[0])))
onlogv = [k * V * math.log2(V) for V in sizes]

p.figure(figsize=(10, 5))
p.plot(sizes, times, marker="o", color="red", label="Measured Time (Dijkstra)")
p.plot(sizes, onlogv, linestyle="--", color="blue", label="O((V+E) log V) Reference")

p.xlabel("Number of Vertices (V)")
p.ylabel("Time (seconds)")
p.title("Time Complexity of Dijkstra's Algorithm")
p.legend()
p.grid(True)
p.show()