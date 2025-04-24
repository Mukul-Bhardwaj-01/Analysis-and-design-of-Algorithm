#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist)
{
    int V = dist.size();
    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void printMatrix(const vector<vector<int>>& dist) 
{
    int V = dist.size();
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int V = 4;
    vector<vector<int>> dist = {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };

    floydWarshall(dist);

    cout << "All-Pairs Shortest Path Matrix:\n";
    printMatrix(dist);

    return 0;
}