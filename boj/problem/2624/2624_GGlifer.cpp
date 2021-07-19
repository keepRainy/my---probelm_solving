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
    int T; cin >> T;
    int K; cin >> K;
    int P[K+1], N[K+1];
    for (int i=1; i<=K; i++)
        cin >> P[i] >> N[i];

    // Process
    int dp[K+1][T+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for (int i=1; i<=K; i++) {
        for (int j=T; j>=0; j--) {
            for (int k=0; k<=N[i]; k++) {
                if (j-k*P[i] >= 0) {
                    dp[i][j] += dp[i-1][j-k*P[i]];
                } else break;
            }
        }
    }

    // dp[0][0] = 1;
    // for (int i=1; i<=K; i++) {
    //     for (int j=0; j<=T; j++) {
    //         for (int k=0; k<=N[i]; k++) {
    //             if (j-k*P[i] >= 0) {
    //                 dp[i][j] += dp[i-1][j-k*P[i]];
    //             }
    //         }
    //     }
    // }

    // Control : Output
    cout << dp[K][T] << endl;
}

// Helper Functions
/* None */

