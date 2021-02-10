//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point { int y, x, hasGram; };
enum { NOGRAM, GRAM};
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, M, T;
    cin >> N >> M >> T;
    int A[N+1][M+1];
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
            cin >> A[i][j];

    // Process
    queue<Point> que;
    int dp[N+1][M+1][2];
    memset(dp, -1, sizeof(dp));

    dp[1][1][NOGRAM] = 0;
    que.push({1, 1, NOGRAM});

    while (not(que.empty())) {
        int cy = que.front().y;
        int cx = que.front().x;
        int hasGram = que.front().hasGram;
        que.pop();

        if (A[cy][cx] == 2) {
            hasGram = true;
            dp[cy][cx][GRAM] = dp[cy][cx][NOGRAM];
        }
        if (cy == N && cx == M) continue;

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 1 && ny <= N && nx >= 1 && nx <= M) {
                if (hasGram) {
                    if (dp[ny][nx][GRAM] == -1 || dp[ny][nx][GRAM] > dp[cy][cx][GRAM]+1) {
                        dp[ny][nx][GRAM] = dp[cy][cx][GRAM]+1;
                        que.push({ny, nx, GRAM});
                    }
                } else {
                    if (A[ny][nx] != 1) {
                        if (dp[ny][nx][NOGRAM] == -1 || dp[ny][nx][NOGRAM] > dp[cy][cx][NOGRAM]+1) {
                            dp[ny][nx][NOGRAM] = dp[cy][cx][NOGRAM]+1;
                            que.push({ny, nx, NOGRAM});
                        }
                    }
                }
            }
        }
    }

    int INF = T+1;
    int t1 = dp[N][M][NOGRAM];
    if (t1 == -1) { t1 = INF; }
    int t2 = dp[N][M][GRAM];
    if (t2 == -1) { t2 = INF; }
    bool isPossible = min(t1, t2) <= T;

    // Control : Output
    cout << ((isPossible) ? to_string(min(t1, t2)) : "Fail") << endl;
}

// Helper Functions
/* None */

