#include <iostream>
using namespace std;

struct vertex {
    int x;
    int y;
};

float area(vertex a, vertex b, vertex c)
{
    return 0.5 * abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
}

bool isInside(vertex a, vertex b, vertex c, vertex p)
{
    float A = area(a, b, c);
    float A1 = area(p, b, c);
    float A2 = area(a, p, c);
    float A3 = area(a, b, p);
    return (A == A1 + A2 + A3);
}

int main()
{
    vertex v[3];
    cout << "Enter coordinates of triangle (3 vertices):\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "Vertex " << i + 1 << " (x y): ";
        cin >> v[i].x >> v[i].y;
    }
    vertex p;
    cout << "Enter coordinates of the point to check (x y): ";
    cin >> p.x >> p.y;
    if (isInside(v[0], v[1], v[2], p))
        cout << "Point lies inside the triangle.\n";
    else
        cout << "Point lies outside the triangle.\n";
    return 0;
}
