# Travelling Salesman Problem using Dynamic Programming (Held-Karp Algorithm)
<br>
## Problem Statement
<br>
Given a set of `n` cities and the cost of travel between each pair of cities, find the shortest possible route that visits each city exactly once and returns to the origin city.

<br>
## Assumptions
<br>
- The graph is fully connected.
- The distance between cities is stored in a `dist[][]` matrix.
- We use bitmasking to represent subsets of visited cities.

<br>
## Algorithm
<br>
### Input:
- `dist[n][n]`: 2D matrix representing distance between cities
- `n`: number of cities

<br>
### Output:
- Minimum cost of a complete tour

<br>
## Pseudocode
<br>
function tsp(dist, n): let dp[2^n][n] be a 2D array initialized to ∞
<br>
# Base case: Starting from city 0 and visiting only city 0
<br>
dp[1 << 0][0] = 0
<br>
for mask from 0 to 2^n - 1:
    for u from 0 to n-1:
        if (mask & (1 << u)) != 0:
            for v from 0 to n-1:
                if (mask & (1 << v)) == 0:
                    next_mask = mask | (1 << v)
                    dp[next_mask][v] = min(dp[next_mask][v],
                                           dp[mask][u] + dist[u][v])

<br>
# Complete tour: Return to starting city (0)
<br>
min_cost = ∞
for i from 1 to n-1:
    min_cost = min(min_cost, dp[(1 << n) - 1][i] + dist[i][0])

return min_cost

---

## Time Complexity
- **O(n² * 2ⁿ)**
- Bitmasking gives us 2ⁿ subsets
- For each subset and last visited node, we try extending to n possible nodes

## Space Complexity
- **O(n * 2ⁿ)**

---

## Example
For `n = 4`, and distance matrix:

0 10 15 20 
10 0 35 25 
15 35 0 30 
20 25 30 0


The algorithm computes the optimal path covering all cities and returns to the origin with the minimum possible cost.
