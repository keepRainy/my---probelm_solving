//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
char cato[50][50];
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
struct Point { int y, x; };

// Set up : Functions Declaration
bool isValid(int y, int x);
bool isBoundary(int y, int x);
int bfs(int sy, int sx);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> cato[i][j];
        }
    }

    // Process
    int ans = -1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (cato[i][j] == 'L') {
                if (isBoundary(i, j)) {
                    ans = max(ans, bfs(i, j));
                }
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

bool isBoundary(int y, int x)
{
    for (int i=0; i<4; i++) {
        int ay = y + dy[i];
        int ax = x + dx[i];
        if (not(isValid(ay, ax)) || cato[ay][ax] == 'W') {
            return true;
        }
    }
    return false;
}

int bfs(int sy, int sx)
{
    queue<Point> que;
    bool isVisited[N][M];
    memset(isVisited, false, sizeof(isVisited));

    que.push({sy, sx});
    isVisited[sy][sx] = true;

    int time = -1;
    while (not(que.empty())) {
        int size = que.size();
        time++;
        while (size--) {
            int cy = que.front().y;
            int cx = que.front().x;
            que.pop();

            for (int i=0; i<4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (isValid(ny, nx) && cato[ny][nx] == 'L' && not(isVisited[ny][nx])) {
                    isVisited[ny][nx] = true;
                    que.push({ny, nx});
                }
            }
        }
    }

    return time;
}
