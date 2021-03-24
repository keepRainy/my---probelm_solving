//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M, D;
struct Point { int y, x; };
set<Point> E;

// Set up : Functions Declaration
bool operator < (const Point &u, const Point &v);
int tmp(int b1, int b2, int b3);
class Comp {
    int pos;
public:
    Comp(int b) { pos = b; }
    bool operator()(const Point &p1, const Point &p2) const;
};


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M >> D;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            int v; cin >> v;
            if (v == 1) {
                E.insert({i, j});
            }
        }
    }

    // Process
    int ans = -1;
    for (int b1=0; b1<M; b1++) {
        for (int b2=b1+1; b2<M; b2++) {
            for (int b3=b2+1; b3<M; b3++) {
                ans = max(ans, tmp(b1, b2, b3));
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (const Point &u, const Point &v)
{
    return make_pair(u.y, u.x) < make_pair(v.y, v.x);
}

bool Comp::operator()(const Point &p1, const Point &p2) const {
    int d1 = abs(p1.y-N) + abs(p1.x-pos);
    int d2 = abs(p2.y-N) + abs(p2.x-pos);
    return (d1 != d2) ? (d1 < d2) : (p1.x < p2.x);
}

int tmp(int b1, int b2, int b3)
{
    set<Point> R = E;

    int cnt = 0;
    while (not(R.empty())) {
        Point t1 = *min_element(R.begin(), R.end(), Comp(b1));
        int d1 = abs(t1.y-N) + abs(t1.x-b1);

        Point t2 = *min_element(R.begin(), R.end(), Comp(b2));
        int d2 = abs(t2.y-N) + abs(t2.x-b2);

        Point t3 = *min_element(R.begin(), R.end(), Comp(b3));
        int d3 = abs(t3.y-N) + abs(t3.x-b3);

        if (d1 <= D && (R.find(t1) != R.end())) { R.erase(t1), cnt++; }
        if (d2 <= D && (R.find(t2) != R.end())) { R.erase(t2), cnt++; }
        if (d3 <= D && (R.find(t3) != R.end())) { R.erase(t3), cnt++; }

        set<Point> T;
        for (auto p : R) {
            if (p.y+1 < N) {
                T.insert({p.y+1, p.x});
            }
        }

        R = T;
    }

    return cnt;
}
