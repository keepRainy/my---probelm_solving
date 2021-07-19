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
    int N, M;
    cin >> N >> M;
    bool A[300+1][300+1];
    memset(A, false, sizeof(A));
    for (int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        A[x][y] = true;
    }

    // Process
    long dp[300+1][300+1];
    memset(dp, 0, sizeof(dp));

    for (int i=0; i<=300; i++) {
        for (int j=0; j<=300; j++) {
            dp[i][j] = max((i > 0) ? dp[i-1][j] : 0, (j > 0) ? dp[i][j-1] : 0);
            if (A[i][j]) {
                dp[i][j] += max(0, M-(i+j));
            }
        }
    }

    // Control : Output
    cout << dp[300][300] << endl;
}

// Helper Functions
/* None */

