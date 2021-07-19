//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cmath>
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
    int N; string m;
    while (true) {
        cin >> N >> m;
        if (N == 0 && m == "0.00") break;
        int M = (int)(round(stod(m)*100));

        int C[N+1], P[N+1];
        for (int i=1; i<=N; i++) {
            int c; string p;
            cin >> c >> p;
            C[i] = c;
            P[i] = (int)(round(stod(p)*100));
        }

        // Process
        int dp[N+1][M+1];
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=N; i++) {
            for (int j=1; j<=M; j++) {
                dp[i][j] = dp[i-1][j];
                if (j-P[i] >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-P[i]]+C[i]);
                }
            }
        }

        // Control : Output
        cout << dp[N][M] << endl;
    }
}

// Helper Functions
/* None */

