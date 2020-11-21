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
int N;
int A[1000+1];
int dp[1000+1][1000+1];
int MN[1000+1][1000+1];
int MX[1000+1][1000+1];

// Set up : Functions Declaration
int f(int s, int e);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> A[i];

    // Process
    for (int i=1; i<=N; i++) {
        int mx, mn;
        mx = mn = A[i];
        for (int j=i+1; j<=N; j++) {
            mx = max(mx, A[j]);
            mn = min(mn, A[j]);
            MX[i][j] = mx;
            MN[i][j] = mn;
        }
    }

    memset(dp, -1, sizeof(dp));
    int ans = f(1, N);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int f(int s, int e)
{
    if (s == e) return 0;
    if (dp[s][e] != -1) return dp[s][e];
    dp[s][e] = MX[s][e] - MN[s][e];
    for (int i=s; i<e; i++) {
        dp[s][e] = max(dp[s][e], f(s, i)+f(i+1, e));
    }
    return dp[s][e];
}
