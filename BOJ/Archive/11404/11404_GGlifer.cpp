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
#define INF (100*100000+1)

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int dp[N+1][N+1];
    fill(&dp[1][1], &dp[N][N+1], INF);
    for (int i=1; i<=N; i++) { dp[i][i] = 0; }
    int M; cin >> M;
    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    // Process
    for (int m=1; m<=N; m++) {
        for (int f=1; f<=N; f++) {
            for (int t=1; t<=N; t++) {
                if (dp[f][t] > dp[f][m] + dp[m][t]) {
                    dp[f][t] = dp[f][m] + dp[m][t];
                }
            }
        }
    }

    // Control : Output
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << ((dp[i][j] == INF) ? 0 : dp[i][j]) << ' ';
        } cout << endl;
    }
}

// Helper Functions
/* None */

