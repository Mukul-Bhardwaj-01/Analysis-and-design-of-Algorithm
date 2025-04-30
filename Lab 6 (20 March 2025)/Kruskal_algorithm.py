import random
import time
import matplotlib.pyplot as plt

class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            self.parent[root_u] = root_v

def kruskal(n, edges):
    ds = DisjointSet(n)
    mst = []
    edges.sort(key=lambda x: x[2])  # Sort by weight

    for u, v, w in edges:
        if ds.find(u) != ds.find(v):
            mst.append((u, v, w))
            ds.union(u, v)
        if len(mst) == n - 1:
            break

    return mst

def generate_graph(n, extra_edges=0):
    edges = []
    connected = list(range(n))
    random.shuffle(connected)
    
    for i in range(n - 1):
        u, v = connected[i], connected[i + 1]
        edges.append((u, v, random.randint(1, 100)))

    added = set((min(u, v), max(u, v)) for u, v, _ in edges)
    while len(edges) < n - 1 + extra_edges:
        u = random.randint(0, n - 1)
        v = random.randint(0, n - 1)
        if u != v and (min(u, v), max(u, v)) not in added:
            edges.append((u, v, random.randint(1, 100)))
            added.add((min(u, v), max(u, v)))
    
    return edges

sizes = [10, 20, 40, 80, 160]
times = []

for n in sizes:
    edges = generate_graph(n, extra_edges=n)
    start = time.time()
    kruskal(n, edges)
    end = time.time()
    times.append(end - start)

plt.plot(sizes, times, marker='o', color='green', label="Kruskal's Algorithm (O(E*logE))")
plt.xlabel("Number of Nodes")
plt.ylabel("Execution Time (seconds)")
plt.title("Kruskal's Algorithm Time Complexity")
plt.grid(True)
plt.legend()
plt.show()