//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
char board[1000][1000];
int label[1000][1000];
bool isVisited[1000][1000];
struct Point { int y, x; };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);
int bfs(int sy, int sx, int No);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }

    // Process
    map<int,int> cnt;
    int No = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (not(isVisited[i][j]) && board[i][j] == '0') {
                cnt[No] = bfs(i, j, ++No);
            }
        }
    }

    // Control : Output
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j] == '0') {
                cout << 0;
            } else {
                set<int> labels;
                for (int k=0; k<4; k++) {
                    int ay = i + dy[k];
                    int ax = j + dx[k];
                    if (isValid(ay, ax)) {
                        labels.insert(label[ay][ax]);
                    }
                }
                int s = 1;
                for (int l : labels) {
                    s += cnt[l];
                } s %= 10;
                cout << s;
            }
        } cout << endl;
    } cout << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(int sy, int sx, int No)
{
    queue<Point> que;

    que.push({sy, sx});
    isVisited[sy][sx] = true;

    int size = 0;
    while (not(que.empty())) {
        Point c = que.front(); que.pop();
        label[c.y][c.x] = No;
        size++;

        for (int i=0; i<4; i++) {
            int ny = c.y + dy[i];
            int nx = c.x + dx[i];
            if (isValid(ny, nx) && not(isVisited[ny][nx]) && board[ny][nx] == '0') {
                isVisited[ny][nx] = true;
                que.push({ny, nx});
            }
        }
    }

    return size;
}
