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
int L[2000], R[2000];
int dp[2000][2000];

// Set up : Functions Declaration
int f(int l, int r);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> L[i];
    for (int i=0; i<N; i++)
        cin >> R[i];

    // Process
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 0);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int f(int l, int r)
{
    if (l == N || r == N) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = max(f(l+1, r), f(l+1, r+1));
    if (L[l] > R[r]) {
        dp[l][r] = max(dp[l][r], f(l, r+1)+R[r]);
    } return dp[l][r];
}
