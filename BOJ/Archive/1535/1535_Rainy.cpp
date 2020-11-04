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
    int L[N+1], J[N+1];
    for (int i=1; i<=N; i++)
        cin >> L[i];
    for (int i=1; i<=N; i++)
        cin >> J[i];

    // Process
    int dp[N+1][100+1];
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=100; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-L[i] > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-L[i]]+J[i]);
            }
        }
    }

    // Control : Output
    cout << dp[N][100] << endl;
}

// Helper Functions
/* None */

