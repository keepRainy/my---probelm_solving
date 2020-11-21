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

    for (int i=1; i<=N; i++) {
        dp[i] = i;
    }

    for (int i=1; i<=N-3; i++) {
        for (int j=i+3; j<=N; j++) {
            dp[j] = max(dp[j], dp[i]*(j-i-1));
        }
    }

    // Control : Output
    cout << dp[N] << endl;
}

// Helper Functions
/* None */

