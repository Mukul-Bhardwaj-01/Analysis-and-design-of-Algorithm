#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int orientation(Point a, Point b, Point c)
{
    int val = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);

    if (val == 0) return 0;
    return (val > 0) ? 1 : -1;
}

void convexHullNaive(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }
    cout << "Convex Hull points:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int pos = 0, neg = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j) continue;
                int dir = orientation(points[i], points[j], points[k]);
                if (dir > 0) pos++;
                else if (dir < 0) neg++;
            }
            if (pos == 0 || neg == 0)
            {
                cout << "(" << points[i].x << ", " << points[i].y << ") ";
                cout << "(" << points[j].x << ", " << points[j].y << ")\n";
            }
        }
    }
}

int main()
{
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHullNaive(points);
    return 0;
}
