import time
import random
import matplotlib.pyplot as p

def fractional_knapsack(capacity, items):
    items.sort(key=lambda x: x[0] / x[1], reverse=True)
    total_value = 0
    for value, weight in items:
        if capacity >= weight:
            capacity -= weight
            total_value += value
        else:
            total_value += value * (capacity / weight)
            break
    return total_value

def generate_items(n):
    return [(random.randint(10, 100), random.randint(1, 50)) for _ in range(n)]

def measure_time(n):
    items = generate_items(n)
    capacity = random.randint(50, 500)
    start_time = time.time()
    fractional_knapsack(capacity, items)
    return time.time() - start_time

def plot_time_complexity():
    input_sizes = [10, 50, 100, 500, 1000, 5000, 10000]
    times = [measure_time(n) for n in input_sizes]
    p.plot(input_sizes, times, marker='o', linestyle='-')
    p.xlabel("Number of Items")
    p.ylabel("Time (seconds)")
    p.title("Time Complexity of Fractional Knapsack Problem")
    p.grid(True)
    p.show()
    
plot_time_complexity()