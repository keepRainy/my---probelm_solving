//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <deque>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int M, N;
char maze[100][100];
bool isVisited[100][100];
int wallCount[100][100];
struct Point { int y, x; };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> M >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> maze[i][j];
        }
    }

    // Process
    deque<Point> deq;

    deq.push_back({0, 0});
    isVisited[0][0] = true;
    wallCount[0][0] = 0;

    while (not(deq.empty())) {
        Point c = deq.front(); deq.pop_front();
        int cy = c.y;
        int cx = c.x;
        if (cy == N-1 && cx == M-1) break;

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (isValid(ny, nx)) {
                if (maze[ny][nx] == '0') {
                    if (not(isVisited[ny][nx]) || wallCount[cy][cx] < wallCount[ny][nx]) {
                        isVisited[ny][nx] = true;
                        wallCount[ny][nx] = wallCount[cy][cx];
                        deq.push_front({ny, nx});
                    }
                }
                if (maze[ny][nx] == '1') {
                    if (not(isVisited[ny][nx]) || wallCount[cy][cx]+1 < wallCount[ny][nx]) {
                        isVisited[ny][nx] = true;
                        wallCount[ny][nx] = wallCount[cy][cx]+1;
                        deq.push_back({ny, nx});
                    }
                }

            }
        }
    }

    // Control : Output
    cout << wallCount[N-1][M-1] << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}
