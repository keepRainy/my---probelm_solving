//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point { int x, y; };

// Set up : Functions Declaration
bool operator < (Point u, Point v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    vector<Point> P(N);
    for (int i=0; i<N; i++)
        cin >> P[i].x >> P[i].y;

    // Process
    sort(P.begin(), P.end());

    int INF = numeric_limits<int>::max();
    long ans = 0;
    for (int i=0; i<N; i++) {
        int l = INF, r = INF;
        if (i-1 >= 0 && P[i-1].y == P[i].y) {
            l = P[i].x - P[i-1].x;
        }
        if (i+1 < N && P[i+1].y == P[i].y) {
            r = P[i+1].x - P[i].x;
        }
        int d = min(l, r);
        if (d != INF) ans += d;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (Point u, Point v)
{
    return make_pair(u.y, u.x) < make_pair(v.y, v.x);
}
