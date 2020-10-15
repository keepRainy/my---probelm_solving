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
#define MOD 1'000'000'000

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int n; cin >> n;

    // Process
    int dp[max(1,abs(n))+1];
    dp[0] = 0;
    dp[1] = 1;
    if (n >= 0) {
        for (int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
            dp[i] %= MOD;
        }
    } else {
        n = abs(n);
        for (int i=2; i<=n; i++) {
            dp[i] = dp[i-2] - dp[i-1];
            dp[i] %= MOD;
        }
    }

    // Control : Output
    cout << ((dp[n] > 0) ? 1 : (dp[n] < 0) ? -1 : 0) << endl;
    cout << abs(dp[n]) << endl;
}

// Helper Functions
/* None */

