//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
char board[30][30];
bool isVisited[30][30];
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);
int dfs(int cy, int cx, int cnt, int res);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int tc = 0;
    while (cin >> N >> M) {
        tc++;
        int res = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                cin >> board[i][j];
                if (board[i][j] == '.') { res++; }
            }
        }

        // Process
        int ans = -1;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (board[i][j] == '.') {
                    isVisited[i][j] = true;

                    int temp = dfs(i, j, 0, res-1);
                    if (temp != -1) {
                        if (ans == -1 || ans > temp) {
                            ans = temp;
                        }
                    }

                    isVisited[i][j] = false;
                }
            }
        }

        // Control : Output
        printf("Case %d: %d\n", tc, ans);
    }
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}

int dfs(int cy, int cx, int cnt, int res)
{
    bool canMove = false;
    for (int i=0; i<4; i++) {
        int ay = cy + dy[i];
        int ax = cx + dx[i];
        if (isValid(ay, ax) && board[ay][ax] == '.' && not(isVisited[ay][ax])) {
            canMove = true;
            break;
        }
    }

    if (not(canMove)) {
        return (res == 0) ? cnt : -1;
    }

    int ret = -1;
    for (int i=0; i<4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (isValid(ny, nx) && board[ny][nx] == '.' && not(isVisited[ny][nx])) {
            while (isValid(ny, nx) && board[ny][nx] == '.' && not(isVisited[ny][nx])) {
                isVisited[ny][nx] = true;
                res--;
                ny += dy[i];
                nx += dx[i];
            }
            ny -= dy[i];
            nx -= dx[i];

            int temp = dfs(ny, nx, cnt+1, res);
            if (temp != -1) {
                if (ret == -1 || ret > temp) {
                    ret = temp;
                }
            }

            while (ny != cy || nx != cx) {
                isVisited[ny][nx] = false;
                res++;
                ny -= dy[i];
                nx -= dx[i];
            }
        }
    }

    return ret;
}

