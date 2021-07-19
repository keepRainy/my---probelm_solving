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
int N, M, K;
char A[100][100];
int dp[100][100][80];
string W;
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);
int f(int cy, int cx, int idx);

int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M >> K;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> A[i][j];
    cin >> W;

    // Process
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (A[i][j] == W.back()) {
                ans += f(i, j, W.length()-1);
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}

int f(int cy, int cx, int idx)
{
    if (idx == 0) return 1;
    if (dp[cy][cx][idx] != -1) return dp[cy][cx][idx];

    dp[cy][cx][idx] = 0;
    for (int i=0; i<4; i++) {
        for (int k=1; k<=K; k++) {
            int py = cy + k*dy[i];
            int px = cx + k*dx[i];
            if (not(isValid(py, px))) break;
            if (not(A[py][px] == W[idx-1])) continue;
            dp[cy][cx][idx] += f(py, px, idx-1);
        }
    }

    return dp[cy][cx][idx];
}

