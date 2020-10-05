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
    int N, M;
    cin >> N >> M;
    int board[N+1][M+1];
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            char c; cin >> c;
            board[i][j] = c - '0';
        }
    }

    // Process
    int dp[N+1][M+1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=M; j++) {
            if (board[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                ans = max(ans, dp[i][j]*dp[i][j]);
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

