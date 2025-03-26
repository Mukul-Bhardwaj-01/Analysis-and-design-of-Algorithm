#include <iostream>
#include <climits>
using namespace std;

#define V 5
int minDistance(int dist[], bool visited[])
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                }
        }
    }
    cout << "Vertex   Distance from Source " << src << "\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t " << dist[i] << "\n";
    }
}

int main()
{
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 0, 4},
        {5, 2, 0, 0, 3},
        {0, 0, 4, 3, 0}
    };
    int src;
    cout << "Enter the source vertex (0 to " << V - 1 << "): ";
    cin >> src;
    dijkstra(graph, src);
    return 0;
}
