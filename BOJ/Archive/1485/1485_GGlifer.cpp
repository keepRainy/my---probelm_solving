//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point { int x, y; };

// Set up : Functions Declaration
long dist(Point &u, Point &v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        Point P[4];
        for (auto &p : P)
            cin >> p.x >> p.y;

        // Process
        sort(P, P+4, [](Point &u, Point &v){
            return make_pair(u.x, u.y) < make_pair(v.x, v.y);
        });

        long d01 = dist(P[0], P[1]);
        long d02 = dist(P[0], P[2]);
        long d13 = dist(P[1], P[3]);
        long d23 = dist(P[2], P[3]);
        long d03 = dist(P[0], P[3]);
        long d12 = dist(P[1], P[2]);

        bool isSquare = (d01 == d02) &&
                        (d13 == d23) &&
                        (d01 == d13) &&
                        (d03 == d12);

        // Control : Output
        cout << ((isSquare) ? 1 : 0) << endl;
    }
}

// Helper Functions
long dist(Point &u, Point &v)
{
    long dx = v.x - u.x;
    long dy = v.y - u.y;
    return dx*dx + dy*dy;
}

