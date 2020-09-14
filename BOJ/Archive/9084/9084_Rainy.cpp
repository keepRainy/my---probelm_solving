//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        int C[N+1];
        for (int i=1; i<=N; i++) {
            cin >> C[i];
        }
        int M; cin >> M;

        // Process
        int dp[N+1][M+1];
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=N; i++) {
            dp[i][0] = 1;
            for (int j=1; j<=M; j++) {
                dp[i][j] += dp[i-1][j];
                if (j-C[i] >= 0) {
                    dp[i][j] += dp[i][j-C[i]];
                }
            }
        }

        // Control : Output
        cout << dp[N][M] << endl;
    }
}

// Helper Functions
/* None */

