//
//  BOJ
//  ver.C++
//
//  Created by Rainy
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

    // Process
    int dp[40+1];
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i=3; i<=40; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    // Set up : Input
    int N; cin >> N;
    int M; cin >> M;
    int V[M+2];
    V[0] = 0;
    V[M+1] = N+1;
    for (int i=1; i<=M; i++) {
        cin >> V[i];
    }

    // Process
    int ans = 1;
    for (int i=0; i<=M; i++) {
        int s = V[i]+1;
        int e = V[i+1]-1;
        int n = e-s+1;
        ans *= dp[n];
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

