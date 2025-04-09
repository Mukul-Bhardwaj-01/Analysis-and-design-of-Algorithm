#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct Point {
    int x, y;
};

bool areCollinear(Point a, Point b, Point c)
{
    return (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) == 0;
}

void generateAllTriangles(vector<Point> &points)
{
    int n = points.size();
    vector<tuple<Point, Point, Point>> triangles;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if (areCollinear(points[i], points[j], points[k]))
                    continue;
                triangles.push_back({points[i], points[j], points[k]});
            }
        }
    }

    cout << "Valid non-collinear triangles:\n";
    for (auto &[a, b, c] : triangles)
    {
        cout << "Triangle: (" << a.x << "," << a.y << ") - (" << b.x << "," << b.y << ") - (" << c.x << "," << c.y << ")\n";
    }
}

int main()
{
    vector<Point> points = {{0, 0}, {1, 0}, {0, 1}, {2, 2}};
    generateAllTriangles(points);
    return 0;
}
