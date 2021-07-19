//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point { double y, x; };

// Set up : Functions Declaration
double getDist(const Point &u, const Point &v);
Point operator + (Point u, Point v);
Point operator - (Point u, Point v);
Point operator * (Point p, int v);
Point& operator /= (Point &p, int v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    Point A{}, B{}, C{}, D{};
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    // Process
    int std = 10e6;
    Point DM = B - A;
    DM /= std;
    Point DG = D - C;
    DG /= std;

    double ans = numeric_limits<double>::max();
    for (int i=0; i<=10e6; i++) {
        Point CM = A + (DM * i);
        Point CG = C + (DG * i);
        ans = min(ans, getDist(CM, CG));
    }

    // Control : Output
    cout << fixed;
    cout.precision(10);
    cout << ans << endl;
}

// Helper Functions
double getDist(const Point &u, const Point &v)
{
    double dx = u.x - v.x;
    double dy = u.y - v.y;
    return sqrt(dx*dx + dy*dy);
}

Point operator + (Point u, Point v)
{
    return {u.x + v.x, u.y + v.y};
}

Point operator - (Point u, Point v)
{
    return {u.x - v.x, u.y - v.y};
}

Point operator * (Point p, int v)
{
    return {p.x * v, p.y * v};
}

Point& operator /= (Point &p, int v)
{
    p.x /= v;
    p.y /= v;
    return p;
}

