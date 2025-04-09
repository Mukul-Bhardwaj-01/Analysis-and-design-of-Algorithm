#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

int find(vector<int>& parent, int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (xroot != yroot)
    {
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else
        {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

vector<Edge> kruskalMST(vector<Edge>& edges, int numVertices)
{
    vector<Edge> result;

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
    {
        return a.weight < b.weight;
    });

    vector<int> parent(numVertices);
    vector<int> rank(numVertices, 0);

    for (int i = 0; i < numVertices; ++i)
        parent[i] = i;

    int edgeCount = 0;
    int i = 0;

    while (edgeCount < numVertices - 1 && i < edges.size())
    {
        Edge nextEdge = edges[i++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y)
        {
            result.push_back(nextEdge);
            unionSets(parent, rank, x, y);
            edgeCount++;
        }
    }

    return result;
}

int main()
{
    int numVertices = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> mst = kruskalMST(edges, numVertices);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst)
    {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
    }

    return 0;
}