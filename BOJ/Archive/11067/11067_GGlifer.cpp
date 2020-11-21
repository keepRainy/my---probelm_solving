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
struct Cafe { int x, y; };

// Set up : Functions Declaration
bool operator < (const Cafe &u, const Cafe &v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        vector<Cafe> cafes(N+1);
        for (int i=1; i<=N; i++) {
            cin >> cafes[i].x >> cafes[i].y;
        }

        // Process
        cafes[0] = {-1, 0};
        sort(cafes.begin(), cafes.end());

        int idx = 1;
        while (idx <= N) {
            if (cafes[idx].x == cafes[idx-1].x) {
                idx++;
            } else if (cafes[idx].y == cafes[idx-1].y) {
                idx++;
            } else {
                auto spos = cafes.begin() + idx;
                int x = cafes[idx].x;
                while (++idx <= N && x == cafes[idx].x) {}
                auto epos = cafes.begin() + idx;
                reverse(spos, epos);
            }
        }

        // Control : Output
        int M; cin >> M;
        for (int i=0; i<M; i++) {
            int k; cin >> k;
            cout << cafes[k].x << ' ' << cafes[k].y << endl;
        }
    }
}

// Helper Functions
bool operator < (const Cafe &u, const Cafe &v)
{
    return make_pair(u.x, u.y) < make_pair(v.x, v.y);
}
