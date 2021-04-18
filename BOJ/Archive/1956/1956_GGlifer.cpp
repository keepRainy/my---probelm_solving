//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
#define INF (400*10000 + 1)

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int V, E;
    cin >> V >> E;
    int dp[V+1][V+1];
    fill(&dp[1][1], &dp[V][V+1], INF);
    for (int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = c;
    }

    // Process
    for (int m=1; m<=V; m++) {
        for (int f=1; f<=V; f++) {
            for (int t=1; t<=V; t++) {
                if (dp[f][t] > dp[f][m] + dp[m][t]) {
                    dp[f][t] = dp[f][m] + dp[m][t];
                }
            }
        }
    }

    int ans = INF;
    for (int i=1; i<=V; i++) {
        ans = min(ans, dp[i][i]);
    }

    // Control : Output
    cout << ((ans == INF) ? -1 : ans) << endl;
}

// Helper Functions
/* None */
