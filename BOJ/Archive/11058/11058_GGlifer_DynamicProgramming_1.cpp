//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>

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
    long dp[N+1];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i=4; i<=N; i++) {
        dp[i] = i;
        for (int j=1; j<=i-3; j++) {
            dp[i] = max(dp[i], dp[j]*(i-j-1));
        }
    }

    // Control : Output
    cout << dp[N] << endl;
}

// Helper Functions
/* None */

