//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int M, N;
char A[100][100];
struct Point { int y, x, d; };
bool isVisited[100][100][4];
enum Direction { East, West, South, North };
enum Turn { Left, Right };
int D[4][2] = {
        // Left, Right
        {North, South}, // East
        {South, North}, // West
        {East, West}, // South
        {West, East}  // North
};
int dy[4] = {0, 0, +1, -1};
int dx[4] = {+1, -1, 0, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);


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
    int sy, sx, sd;
    cin >> sy >> sx >> sd;
    int ey, ex, ed;
    cin >> ey >> ex >> ed;

    // Process
    sy--, sx--, sd--;
    ey--, ex--, ed--;

    queue<Point> que;

    isVisited[sy][sx][sd] = true;
    que.push({sy, sx, sd});

    int ans = -1;
    while (not(que.empty())) {
        ans++;
        auto sz = que.size();
        while (sz--) {
            auto [cy, cx, cd] = que.front();
            que.pop();

            // Control : Output
            if (cy == ey && cx == ex && cd == ed) {
                cout << ans << endl;
                exit(0);
            }

            for (int i=1; i<=3; i++) {
                int ny = cy + i*dy[cd];
                int nx = cx + i*dx[cd];
                if (isValid(ny, nx) && A[ny][nx] == '0') {
                    if (not(isVisited[ny][nx][cd])) {
                        isVisited[ny][nx][cd] = true;
                        que.push({ny, nx, cd});
                    }
                } else break;
            }
            for (int i=0; i<2; i++) {
                int nd = D[cd][i];
                if (not(isVisited[cy][cx][nd])) {
                    isVisited[cy][cx][nd] = true;
                    que.push({cy, cx, nd});
                }
            }
        }
    }
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < M && x >= 0 && x < N;
}
