#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int n, int col)
{
    for (int k = 0; k < n; ++k)
    {
        if (graph[node][k] && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>>& graph, vector<int>& color, int m, int n)
{
    if (node == n) return true;

    for (int col = 1; col <= m; ++col)
    {
        if (isSafe(node, graph, color, n, col))
        {
            color[node] = col;
            if (solve(node + 1, graph, color, m, n))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m, int n)
{
    vector<int> color(n, 0);

    if (solve(0, graph, color, m, n))
    {
        cout << "Solution Exists: Node Colors are -> ";
        for (int c : color)
            cout << char('a' + c - 1) << " ";
        cout << endl;
        return true;
    }
    else
    {
        cout << "No solution exists.\n";
        return false;
    }
}

int main()
{
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of colors: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];

    graphColoring(graph, m, n);

    return 0;
}
