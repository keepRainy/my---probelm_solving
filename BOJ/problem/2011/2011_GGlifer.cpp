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
    string code; cin >> code;

    // Control : Output
    if (code[0] == '0') {
        cout << 0 << endl;
        exit(0);
    }

    // Process
    int N = code.length();
    int dp[N+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for (int i=2; i<=N; i++) {
        int c = code[i-1] - '0';
        int p = code[i-2] - '0';

        if (c != 0) {
            dp[i] += dp[i-1];
        }
        if (10*p+c >= 10 && 10*p+c <= 26) {
            dp[i] += dp[i-2];
        }

        // Control : Output
        if (dp[i] == 0) {
            cout << 0 << endl;
            exit(0);
        }

        dp[i] %= 1000000;
    }

    // Control : Output
    cout << dp[N] << endl;
}

// Helper Functions
/* None */

