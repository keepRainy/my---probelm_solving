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
int N, M;
int board[100][100];
bool isVisited[100][100];
enum Status { AIR, CHEESE, HOLE };
struct Point { int y, x; };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);
void checkStatus();
void cheeseMelt();
int residualCheese();


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
    int time = 0;
    int res, prevRes = -1;
    while ((res = residualCheese()) > 0) {
        time++;
        checkStatus();
        cheeseMelt();
        prevRes = res; 
    }

    // Control : xOutput
    cout << time << endl;
    cout << prevRes << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}

void checkStatus()
{
    queue<Point> que;
    memset(isVisited, false, sizeof(isVisited));
    que.push({0, 0});
    isVisited[0][0] = true;

    while (not(que.empty())) {
        int cy = que.front().y;
        int cx = que.front().x;
        que.pop();

        board[cy][cx] = AIR;
        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (isValid(ny, nx) && board[ny][nx] != CHEESE && not(isVisited[ny][nx])) {
                isVisited[ny][nx] = true;
                que.push({ny, nx});
            }
        }
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (not(isVisited[i][j]) && board[i][j] != CHEESE) {
                board[i][j] = HOLE;
            }
        }
    }
}

void cheeseMelt()
{
    queue<Point> que;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j] == CHEESE) {
                for (int k=0; k<4; k++) {
                    int ay = i + dy[k];
                    int ax = j + dx[k];
                    if (isValid(ay, ax) && board[ay][ax] == AIR) {
                        que.push({i, j});
                        break;
                    }
                }
            }
        }
    }

    while (not(que.empty())) {
        int cy = que.front().y;
        int cx = que.front().x;
        que.pop();
        board[cy][cx] = AIR;
    }
}

int residualCheese()
{
    int res = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j] == CHEESE) { res++; }
        }
    }
    return res;
}
