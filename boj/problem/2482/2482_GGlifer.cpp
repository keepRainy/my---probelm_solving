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
#define MOD 1000000003

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, K;
    cin >> N >> K;

    // Process
    int dp[N][K+1];
    memset(dp, 0, sizeof(dp));
    
    for (int i=1; i<=N; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for (int i=2; i<=N-1; i++) {
        for (int j=2; j<=K; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-2][j-1];
            dp[i][j] %= MOD;
        }
    }

    int ans = (dp[N-3][K-1] + dp[N-1][K]) % MOD;

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

