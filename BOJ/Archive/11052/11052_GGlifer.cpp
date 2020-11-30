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
    int P[N+1];
    for (int i=1; i<=N; i++)
        cin >> P[i];

    // Process
    int dp[N+1];
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=N; i++) {
        for (int j=i; j<=N; j++) {
            dp[j] = max(dp[j], dp[j-i]+P[i]);
        }
    }

    // Control : Output
    cout << dp[N] << endl;
}

// Helper Functions
/* None */

