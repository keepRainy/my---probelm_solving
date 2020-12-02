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
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Process
    long dp[65+1][9+1];
    memset(dp, 0, sizeof(dp));
    for (int i=0; i<=9; i++) {
        dp[1][i] = 1;
    }
    for (int i=2; i<=65; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=j; k<=9; k++) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;

        // Control : Output
        cout << dp[N+1][0] << endl;
    }
}

// Helper Functions
/* None */

