//
//  BOJ
//  ver.C++
//
//  Created by Rainy
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
    long dp[30+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    dp[4] = 14;
    for (int i=5; i<=30; i++) {
        for (int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-1-j];
        }
    }

    // Set up : Input
    while (true) {
        int N; cin >> N;
        if (N == 0) break;

        // Control : Output
        cout << dp[N] << endl;
    }
}

// Helper Functions
/* None */

