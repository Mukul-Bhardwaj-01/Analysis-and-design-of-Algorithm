import time
import random
import matplotlib.pyplot as p

def is_left(p, q, r):
    return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0]) >= 0

def convex_hull_naive(points):
    n = len(points)
    hull = set()
    for i in range(n):
        for j in range(i+1, n):
            left = right = 0
            for k in range(n):
                if k == i or k == j:
                    continue
                if is_left(points[i], points[j], points[k]):
                    left += 1
                else:
                    right += 1
            if left == 0 or right == 0:
                hull.add(points[i])
                hull.add(points[j])
    return list(hull)

def generate_points(n):
    return [(random.randint(0, 1000), random.randint(0, 1000)) for _ in range(n)]

sizes = list(range(10, 111, 10))
times = []

for n in sizes:
    pts = generate_points(n)
    start = time.time()
    convex_hull_naive(pts)
    end = time.time()
    times.append(end - start)

p.plot(sizes, times, marker='o', label='Naive Convex Hull (O(n³))')
p.xlabel('Number of Points')
p.ylabel('Execution Time (seconds)')
p.title('Time Complexity of Naive Convex Hull')
p.grid(True)
p.legend()
p.show()