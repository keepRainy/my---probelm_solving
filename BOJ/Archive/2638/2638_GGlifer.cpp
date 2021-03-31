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
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
int A[100][100];
struct Point { int y, x; };
enum { HOLE, CHEESE, AIR };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);
void marking();
bool melting();


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;
    int res = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> A[i][j];
            if (A[i][j] > 0) res++;
        }
    }

    // Process
    int time = 0;
    while (melting()) {
        time++;
    }

    // Control : Output
    cout << time << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}

void marking()
{
    bool isVisited[N][M];
    memset(isVisited, false, sizeof(isVisited));
    queue<Point> que;

    A[0][0] = AIR;
    isVisited[0][0] = true;
    que.push({0, 0});

    while (not(que.empty())) {
        int cy = que.front().y;
        int cx = que.front().x;
        que.pop();

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (isValid(ny, nx) && not(isVisited[ny][nx]) && A[ny][nx] != CHEESE) {
                isVisited[ny][nx] = true;
                A[ny][nx] = AIR;
                que.push({ny, nx});
            }
        }
    }
}

bool melting()
{
    marking();
    vector<Point> P;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (A[i][j] == CHEESE) {
                int cnt = 0;
                for (int k=0; k<4; k++) {
                    int ay = i + dy[k];
                    int ax = j + dx[k];
                    if (isValid(ay, ax) && A[ay][ax] == AIR) cnt++;
                }

                if (cnt >= 2) {
                    P.push_back({i, j});
                }
            }
        }
    }

    for (auto [py, px] : P) {
        A[py][px] = AIR;
    }

    return not(P.empty());
}
