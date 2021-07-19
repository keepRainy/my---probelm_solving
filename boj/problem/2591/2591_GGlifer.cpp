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
    string D; cin >> D;

    // Control : Output
    if (D.empty() || D[0] == '0') {
        cout << 0 << endl;
        exit(0);
    }
    int L = D.length();
    if (L == 1) {
        cout << 1 << endl;
        exit(0);
    }

    // Process
    int dp[L+1];
    memset(dp, 0, sizeof(dp));
    
    dp[0] = dp[1] = 1;
    for (int i=2; i<=L; i++) {
        int c = D[i-1]-'0';
        int p = D[i-2]-'0';

        if (c != 0) {
            dp[i] += dp[i-1];
        }

        if (p != 0 && 10*p+c <= 34) {
            dp[i] += dp[i-2];
        }

        if (dp[i] == 0) {
            break;
        }
    }

    // Control : Output
    cout << dp[L] << endl;
}

// Helper Functions
/* None */

