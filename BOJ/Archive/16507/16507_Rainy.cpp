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
    int R, C, Q;
    cin >> R >> C >> Q;
    int P[R+1][C+1];
    memset(P, 0, sizeof(P));
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            cin >> P[i][j];
        }
    }

    // Process
    int dp[R+1][C+1];
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            dp[i][j] = P[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    // Control : Output
    for (int i=0; i<Q; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int size = (r2-r1+1)*(c2-c1+1);
        int sum = dp[r2][c2] - dp[r1-1][c2] - dp[r2][c1-1] + dp[r1-1][c1-1];
        cout << sum / size << endl;
    }
}

// Helper Functions
/* None */

