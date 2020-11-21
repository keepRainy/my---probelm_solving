//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point { long x, y; };

// Set up : Functions Declaration
Point getVector(Point s, Point e);
long getCross(Point v1, Point v2);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    Point P[N];
    for (int i=0; i<N; i++)
        cin >> P[i].x >> P[i].y;

    // Process
    long size = 0;
    Point s = P[0];
    for (int i=1; i<N-1; i++) {
        Point e1 = P[i];
        Point e2 = P[i+1];
        Point v1 = getVector(s, e1);
        Point v2 = getVector(s, e2);
        long D = getCross(v1, v2);
        size += D;
    }

    // Control : Output
    cout << fixed;
    cout.precision(1);
    cout << fabs(size / 2.0) << endl;
}

// Helper Functions
Point getVector(Point s, Point e)
{
    return {e.x - s.x, e.y - s.y};
}

long getCross(Point v1, Point v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}
