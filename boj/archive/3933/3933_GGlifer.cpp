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

    // Process
    int S = (1<<15);
    int dp[S][4+1];
    memset(dp, 0, sizeof(dp));
    for (int i=1; i*i<S; i++) {
        dp[i*i][1] = 1;

        for (int j=i*i; j<S; j++) {
            dp[j][2] += dp[j-i*i][1];
            dp[j][3] += dp[j-i*i][2];
            dp[j][4] += dp[j-i*i][3];
        }

//        for (int j=1; j+i*i<S; j++) {
//            dp[j+i*i][2] += dp[j][1];
//            dp[j+i*i][3] += dp[j][2];
//            dp[j+i*i][4] += dp[j][3];
//        }
    }

    // Set up : Input
    while (true) {
        int N; cin >> N;
        if (N == 0) break;

        // Process
        int ans = 0;
        for (int i=1; i<=4; i++) {
            ans += dp[N][i];
        }

        // Control : Output
        cout << ans << endl;
    }
}

// Helper Functions
/* None */

