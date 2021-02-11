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
    int N, T;
    cin >> N >> T;
    int K[N+1], S[N+1];
    for (int i=1; i<=N; i++)
        cin >> K[i] >> S[i];

    // Process
    int dp[N+1][T+1];
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=T; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-K[i] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-K[i]]+S[i]);
            }
        }
    }

    // Control : Output
    cout << dp[N][T] << endl;
}

// Helper Functions
/* None */

