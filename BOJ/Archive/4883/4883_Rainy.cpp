//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
#define INF INT_MAX

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, tc = 0;
    while (true) {
        cin >> N;
        if (N == 0) break;

        tc++;
        int G[N][3];
        for (int i=0; i<N; i++) {
            for (int j=0; j<3; j++) {
                cin >> G[i][j];
            }
        }

        // Process
        int dp[N][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = INF;
        dp[0][1] = G[0][1];
        dp[0][2] = G[0][2] + dp[0][1];

        for (int i=1; i<N; i++) {
            dp[i][0] = G[i][0] + min(dp[i-1][0],
                                        dp[i-1][1]);
            dp[i][1] = G[i][1] + min(dp[i][0],
                                     min(dp[i-1][0],
                                         min(dp[i-1][1],
                                                dp[i-1][2])));
            dp[i][2] = G[i][2] + min(dp[i][1],
                                     min(dp[i-1][1],
                                            dp[i-1][2]));
        }

        // Control : Output
        printf("%d. %d\n", tc, dp[N-1][1]);
    }
}

// Helper Functions
/* None */

