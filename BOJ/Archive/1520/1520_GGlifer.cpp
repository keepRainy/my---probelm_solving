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
int M, N;
int A[500][500];
int dp[500][500];
int dy[4] = {-1, 0, 0, +1};
int dx[4] = {0, -1, +1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);
int f(int cy, int cx);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> M >> N;
    for (int i=0; i<M; i++)
        for (int j=0; j<N; j++)
            cin >> A[i][j];

    // Process
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    int ans = f(M-1, N-1);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < M && x >= 0 && x < N;
}

int f(int cy, int cx)
{
    if (dp[cy][cx] != -1) return dp[cy][cx];
    dp[cy][cx] = 0;
    for (int i=0; i<4; i++) {
        int ay = cy + dy[i];
        int ax = cx + dx[i];
        if (isValid(ay, ax) && A[ay][ax] > A[cy][cx]) {
            dp[cy][cx] += f(ay, ax);
        }
    } return dp[cy][cx];
}
