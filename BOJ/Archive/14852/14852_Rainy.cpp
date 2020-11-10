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
#define MOD 1'000'000'007

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
    int dp1[N+1];
    memset(dp1, 0, sizeof(dp1));
    dp1[0] = 1;
    dp1[1] = 2;
    int dp2[N+1];
    memset(dp2, 0, sizeof(dp2));
    dp2[0] = 1;
    dp2[1] = 3;

    for (int i=2; i<=N; i++) {
        dp1[i] = dp2[i-1]*2;
        dp1[i] %= MOD;
        dp1[i] += dp1[i-2];
        dp1[i] %= MOD;

        dp2[i] = dp2[i-1] + dp1[i];
        dp2[i] %= MOD;
    }

    // Control : Output
    cout << dp1[N] << endl;
}

// Helper Functions
/* None */

