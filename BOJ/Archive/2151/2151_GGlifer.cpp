//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
struct Point { int y, x; };
struct Light { Point p; int d; };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
#define INF 987654321

// Set up : Functions Declaration
bool isValid(int y, int x);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;
    char board[N][N];
    vector<Point> door;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> board[i][j];
            if (board[i][j] == '#') {
                door.push_back({i, j});
            }
        }
    }

    // Process
    queue<Light> que;
    // deque<Light> deq;
    bool isVisited[N][N][4];
    memset(isVisited, false, sizeof(isVisited));
    int isCount[N][N][4];
    memset(isCount, -1, sizeof(isCount));

    Point sd = door.front();
    Point ed = door.back();
    for (int i=0; i<4; i++) {
        que.push({sd, i});
        isVisited[sd.y][sd.x][i] = true;
        isCount[sd.y][sd.x][i] = 0;
    }

    int ans = INF;
    while (not(que.empty())) {
        Light cl = que.front(); que.pop();
        int cy = cl.p.y;
        int cx = cl.p.x;
        int cd = cl.d;
        int cnt = isCount[cy][cx][cd];

        if (cy == ed.y && cx == ed.x) {
            ans = min(ans, cnt);
            continue;
            // ans = cnt;
            // break;
        }

        int ny = cy + dy[cd];
        int nx = cx + dx[cd];
        if (isValid(ny, nx)) {
            if (board[ny][nx] != '*') {
                if (not(isVisited[ny][nx][cd]) || isCount[ny][nx][cd] > cnt) {
                    isVisited[ny][nx][cd] = true;
                    isCount[ny][nx][cd] = cnt;
                    que.push({{ny, nx}, cd});
                    // deq.push_front({{ny, nx}, cd});
                }
            }
        }

        if (board[cy][cx] == '!') {
            for (int i=0; i<4; i++) {
                if (i == cd || 3-i == cd) continue;
                ny = cy + dy[i];
                nx = cx + dx[i];
                if (isValid(ny, nx)) {
                    if (board[ny][nx] != '*') {
                        if (not(isVisited[ny][nx][i]) || isCount[ny][nx][i] > cnt+1) {
                            isVisited[ny][nx][i] = true;
                            isCount[ny][nx][i] = cnt+1;
                            que.push({{ny, nx}, i});
                            // deq.push_back({{ny, nx}, i});
                        }
                    }
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
    return y >= 0 && y < N && x >= 0 && x < N;
}
