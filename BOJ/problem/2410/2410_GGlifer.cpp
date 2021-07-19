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

    // Set up : Input
    int N; cin >> N;

    // Process
    int dp[N+1];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;

    for (int i=2; i<=N; i++) {
        dp[i] += dp[i-1];
        if (i%2 == 0) {
            dp[i] += dp[i/2];
            dp[i] %= 1'000'000'000;
        }
    }

    // Control : Output
    cout << dp[N] << endl;
}

// Helper Functions
/* None */

