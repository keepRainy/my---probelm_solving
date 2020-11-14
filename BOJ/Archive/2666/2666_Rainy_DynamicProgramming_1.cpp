//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
#define INF 987654321

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int s1, s2;
    cin >> s1 >> s2;
    int M; cin >> M;
    int D[M+1];
    for (int i=1; i<=M; i++)
        cin >> D[i];

    // Process
    int dp[M+1][N+1][N+1];
    fill(&dp[0][0][0], &dp[M][N][N+1], INF);

    dp[0][s1][s2] = dp[0][s2][s1] = 0;
    for (int i=1; i<=M; i++) {
        int d = D[i];
        for (int a=1; a<=N; a++) {
            for (int b=1; b<=N; b++) {
                if (a == b) continue;
                dp[i][d][b] = min(dp[i][d][b], dp[i-1][a][b] + abs(a-d));
                dp[i][b][d] = min(dp[i][b][d], dp[i-1][a][b] + abs(a-d));
                dp[i][d][a] = min(dp[i][d][a], dp[i-1][a][b] + abs(b-d));
                dp[i][a][d] = min(dp[i][a][d], dp[i-1][a][b] + abs(b-d));
            }
        }
    }

    int ans = INF;
    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            ans = min(ans, dp[M][i][j]);
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

