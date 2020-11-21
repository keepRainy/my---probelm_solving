//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
bool isImpossible[100+1];
int dp[100+1][40+1];

// Set up : Functions Declaration
int f(int n, int c);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int d; cin >> d;
        isImpossible[d] = true;
    }

    // Process
    memset(dp, -1, sizeof(dp));
    int ans = f(1, 0);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int f(int n, int c)
{
    if (n > N) return 0;
    if (dp[n][c] != -1) return dp[n][c];
    if (isImpossible[n]) return dp[n][c] = f(n+1, c);

    dp[n][c] = min({
        10000 + f(n+1, c),
        25000 + f(n+3, c+1),
        37000 + f(n+5, c+2),
    });
    if (c >= 3) {
        dp[n][c] = min(dp[n][c], f(n+1, c-3));
    }
    return dp[n][c];
}
