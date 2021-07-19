//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
enum Status { R, C, D };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    bool isWall[N+1][N+1];
    memset(isWall, false, sizeof(isWall));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cin >> isWall[i][j];
        }
    }

    // Process
    int dp[N+1][N+1][3];
    memset(dp, 0, sizeof(dp));
    dp[1][2][R] = 1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (not(isWall[i][j])) {
                dp[i][j][R] += dp[i][j-1][R];
                dp[i][j][R] += dp[i][j-1][D];

                dp[i][j][C] += dp[i-1][j][C];
                dp[i][j][C] += dp[i-1][j][D];

                if (not(isWall[i-1][j]) && not(isWall[i][j-1])) {
                    dp[i][j][D] += dp[i-1][j-1][R];
                    dp[i][j][D] += dp[i-1][j-1][C];
                    dp[i][j][D] += dp[i-1][j-1][D];
                }
            }
        }
    }

    // Control : Output
    cout << dp[N][N][R] + dp[N][N][C] + dp[N][N][D] << endl;
}

// Helper Functions
/* None */

