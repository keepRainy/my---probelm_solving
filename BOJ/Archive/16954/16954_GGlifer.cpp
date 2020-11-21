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
char board[8][8];
struct Point { int y, x; };
int dy[9] = {-1, -1, -1,  0,  0,  0, +1, +1, +1};
int dx[9] = {-1,  0, +1, -1,  0, +1, -1,  0, +1};

// Set up : Functions Declaration
bool isValid(int y, int x);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cin >> board[i][j];
        }
    }

    // Process
    queue<Point> que;
    bool isVisited[8][8];
    que.push({7, 0});

    int time = 0;
    while (not(que.empty())) {
        int size = que.size();
        memset(isVisited, false, sizeof(isVisited));
        while (size--) {
            int cy = que.front().y;
            int cx = que.front().x;
            que.pop();

            // Control : Output
            if (cy == 0 && cx == 7) {
                cout << 1 << endl;
                exit(0);
            }

            for (int i=0; i<9; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (isValid(ny, nx) && not(isVisited[ny][nx])) {
                    if (ny-time < 0 || board[ny-time][nx] == '.') {
                        if (ny-(time+1) < 0 || board[ny-(time+1)][nx] == '.') {
                            isVisited[ny][nx] = true;
                            que.push({ny, nx});
                        }
                    }
                }
            }
        }
        time++;
    }

    // Control : Output
    cout << 0 << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < 8 && x >= 0 && x < 8;
}
