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
    string A; cin >> A;
    string B; cin >> B;

    // Process
    int al = A.length();
    int bl = B.length();
    int dp[al+1][bl+1];
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=al; i++) {
        for (int j=1; j<=bl; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Control : Output
    cout << dp[al][bl] << endl;
}

// Helper Functions
/* None */

