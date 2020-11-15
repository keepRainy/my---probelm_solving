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
int N, M;
int A[100+1];
int dp[100+1][50+1];
bool isVisited[100+1][50+1];
#define INF 987654321

// Set up : Functions Declaration
int f(int n, int m);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;
    for (int i=1; i<=N; i++)
        cin >> A[i];

    // Process
    fill(&dp[0][0], &dp[N][M+1], -INF);
    int ans = f(1, M);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int f(int n, int m)
{
    // if (n > N && m > 0) return -INF;
    // if (n > N && m == 0) return 0;
    // if (n <= N && m == 0) return 0;

    if (m == 0) return 0;
    if (n > N) return -INF;
    if (isVisited[n][m]) return dp[n][m];

    isVisited[n][m] = true;
    dp[n][m] = f(n+1, m);
    int sum = 0;
    for (int i=n; i<=N; i++) {
        sum += A[i];
        dp[n][m] = max(dp[n][m], sum+f(i+2, m-1));
    }
    return dp[n][m];
}

