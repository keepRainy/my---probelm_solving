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
    int N, M, K;
    cin >> N >> M >> K;

    // Process
    int ky = (K == 0) ? 0 : (K-1) / M;
    int kx = (K == 0) ? 0 : (K-1) % M;

    int dp[N][M];
    memset(dp, 0, sizeof(dp));

    for (int i=0; i<=ky; i++) {
        dp[i][0] = 1;
    }
    for (int j=0; j<=kx; j++) {
        dp[0][j] = 1;
    }
    for (int i=1; i<=ky; i++) {
        for (int j=1; j<=kx; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    for (int i=ky+1; i<N; i++) {
        dp[i][kx] = dp[ky][kx];
    }
    for (int j=kx+1; j<M; j++) {
        dp[ky][j] = dp[ky][kx];
    }
    for (int i=ky+1; i<N; i++) {
        for (int j=kx+1; j<M; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    // Control : Output
    cout << dp[N-1][M-1] << endl;
}

// Helper Functions
/* None */

