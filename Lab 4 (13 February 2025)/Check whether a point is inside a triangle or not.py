import time
import random
import matplotlib.pyplot as p

def triangle_area(x1, y1, x2, y2, x3, y3):
    return abs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0)

def is_point_in_triangle_area(px, py, ax, ay, bx, by, cx, cy):
    A = triangle_area(ax, ay, bx, by, cx, cy)
    A1 = triangle_area(px, py, bx, by, cx, cy)
    A2 = triangle_area(ax, ay, px, py, cx, cy)
    A3 = triangle_area(ax, ay, bx, by, px, py)
    return abs(A - (A1 + A2 + A3)) < 1e-6

A = (0, 0)
B = (10, 0)
C = (5, 10)

sizes = [5, 50, 500, 5000, 50000]
times = []

for n in sizes:
    start = time.time()
    for _ in range(n):
        px = random.uniform(-10, 20)
        py = random.uniform(-10, 20)
        is_point_in_triangle_area(px, py, *A, *B, *C)
    elapsed = time.time() - start
    times.append(elapsed)

p.plot(sizes, times, marker='o', color='green')
p.title("Time Complexity: Point-in-Triangle-or-not (Area Method)")
p.xlabel("Number of Checks")
p.ylabel("Time (seconds)")
p.grid(True)
p.show()