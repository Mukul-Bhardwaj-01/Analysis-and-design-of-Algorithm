import time
import random
import itertools
import matplotlib.pyplot as p

def is_collinear(p1, p2, p3):
    return (p1[0]*(p2[1] - p3[1]) + 
            p2[0]*(p3[1] - p1[1]) + 
            p3[0]*(p1[1] - p2[1])) == 0

def count_triangles(points):
    count = 0
    for p1, p2, p3 in itertools.combinations(points, 3):
        if not is_collinear(p1, p2, p3):
            count += 1
    return count

def generate_points(n):
    return [(random.randint(0, 1000), random.randint(0, 1000)) for _ in range(n)]

sizes = list(range(10, 51, 5))
times = []

for n in sizes:
    pts = generate_points(n)
    start = time.time()
    count_triangles(pts)
    end = time.time()
    times.append(end - start)

p.plot(sizes, times, marker='o', label='Triangle Generation (O(n³))')
p.xlabel('Number of Points (n)')
p.ylabel('Execution Time (seconds)')
p.title('Time Complexity of Triangle Generation from n Points')
p.grid(True)
p.legend()
p.show()