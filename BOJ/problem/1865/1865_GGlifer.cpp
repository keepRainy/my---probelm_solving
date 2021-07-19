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
struct Edge { int s, e, t; };
#define INF (int)(1e9+7)

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int TC; cin >> TC;

    while (TC--) {
        int N, M, W;
        cin >> N >> M >> W;
        vector<Edge> E;
        for (int i=0; i<M; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            E.push_back({s, e, t});
            E.push_back({e, s, t});
        }
        for (int i=0; i<W; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            E.push_back({s, e, -t});
        }

        // Process
        int D[N+1];
        fill(&D[1], &D[N+1], INF);
        D[1] = 0;

        for (int i=0; i<N-1; i++) {
            for (Edge edge : E) {
                auto [s, e, t] = edge;
                if (D[s] + t < D[e]) {
                    D[e] = D[s] + t;
                }
            }
        }

        bool isPossible = false;
        for (Edge edge : E) {
            auto [s, e, t] = edge;
            if (D[s] + t < D[e]) {
                isPossible = true;
                break;
            }
        }

        // Control : Output
        cout << ((isPossible) ? "YES" : "NO") << endl;
    }
}

// Helper Functions
/* None */
