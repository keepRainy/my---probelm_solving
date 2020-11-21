//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <map>
#include <queue>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int M, N;
bool isWall[50][50][4];
bool isVisited[50][50];
int label[50][50];
map<int,int> S;
int dy[4] = {0, -1, 0, +1};
int dx[4] = {-1, 0, +1, 0};
struct Point { int y, x; };

// Set up : Functions Declaration
bool isValid(int y, int x);
int bfs(int sy, int sx, int no);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            int val; cin >> val;
            for (int k=0; k<4; k++) {
                if (val & (1<<k)) {
                    isWall[i][j][k] = true;
                }
            }
        }
    }

    // Process
    int ans1 = 0, ans2 = -1;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if (not(isVisited[i][j])) {
                ans1++;
                int size = bfs(i, j, ans1);
                S[ans1]= size;
                ans2 = max(ans2, size);
            }
        }
    }

    int ans3 = -1;
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<4; k++) {
                if (isWall[i][j][k]) {
                    int ay = i + dy[k];
                    int ax = j + dx[k];
                    if (isValid(ay, ax)) {
                        int l1 = label[i][j];
                        int l2 = label[ay][ax];
                        if (l1 != l2) {
                            ans3 = max(ans3, S[l1]+S[l2]);
                        }
                    }
                }
            }
        }
    }

    // Control : Output
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < M && x >= 0 && x < N;
}

int bfs(int sy, int sx, int no)
{
    queue<Point> que;
    que.push({sy, sx});
    isVisited[sy][sx] = true;

    int size = 0;

    while (not(que.empty())) {
        int cy = que.front().y;
        int cx = que.front().x;
        que.pop();

        size++;
        label[cy][cx] = no;

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (isValid(ny, nx) && not(isVisited[ny][nx]) && not(isWall[cy][cx][i])) {
                isVisited[ny][nx] = true;
                que.push({ny, nx});
            }
        }
    }

    return size;
}

