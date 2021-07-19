//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int R, C, K;
char board[5][5];
bool isVisited[5][5];
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);
int dfs(int cy, int cx, int dist);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> R >> C >> K;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> board[i][j];
        }
    }
    board[0][C-1] = 'H';

    // Process
    int ans = dfs(R-1, 0, 1);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < R && x >= 0 && x < C;
}

int dfs(int cy, int cx, int dist)
{
    if (dist == K) {
        return (board[cy][cx] == 'H') ? 1 : 0;
    }

    isVisited[cy][cx] = true;
    int ret = 0;

    for (int i=0; i<4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (isValid(ny, nx) && not(isVisited[ny][nx]) && board[ny][nx] != 'T') {
            ret += dfs(ny, nx, dist+1);
        }
    }
    
    isVisited[cy][cx] = false;
    return ret;
}
