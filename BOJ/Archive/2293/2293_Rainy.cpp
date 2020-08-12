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

    // Set up : Input
    int N, K;
    cin >> N >> K;
    int C[N+1];
    for (int i=1; i<=N; i++) {
        cin >> C[i];
    }

    // Process
    int dp[K+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=K; j++) {
            if (j >= C[i]) {
                dp[j] += dp[j-C[i]];
            }
        }
    }

    // Control : Output
    cout << dp[K] << endl;
}

// Helper Functions
/* None */
