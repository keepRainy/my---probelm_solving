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
int dp[20+1][20+1][20+1];
int D[20+1];
#define INF 987654321

// Set up : Functions Declaration
int f(int i, int o1, int o2);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;
    int s1, s2;
    cin >> s1 >> s2;
    cin >> M;
    for (int i=1; i<=M; i++)
        cin >> D[i];

    // Process
    memset(dp, -1, sizeof(dp));
    dp[0][s1][s2] = dp[0][s2][s1] = 0;

    int ans = f(1, s1, s2);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int f(int i, int o1, int o2)
{
    if (i > M) return 0;
    if (dp[i][o1][o2] != -1)
        return dp[i][o1][o2];

    int d = D[i];
    return dp[i][o1][o2] = dp[i][o2][o1] = min(
                abs(o1-d) + f(i+1, d, o2),
                abs(o2-d) + f(i+1, o1, d)
            );
}
