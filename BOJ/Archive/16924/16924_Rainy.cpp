//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
char board[100][100];
bool isChecked[100][100];
struct Cross { int x, y, s; };
int dx[4] = {+1, 0, 0, -1};
int dy[4] = {0, +1, -1, 0};
#define INF 987654321

// Set up : Functions Declaration
bool isValid(int x, int y);
int getMaxS(int x, int y);
void putCross(int x, int y, int s);


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
    int k = 0;
    vector<Cross> crosses;
    for (int x=1; x<N-1; x++) {
        for (int y=1; y<M-1; y++) {
            if (board[x][y] == '*') {
                int s = getMaxS(x, y);
                if (s >= 1) {
                    putCross(x, y, s);
                    k++;
                    crosses.push_back({x+1, y+1, s});
                }
            }
        }
    }

    // Control : Output
    bool isPossible = true;
    for (int x=0; x<N; x++) {
        if (not(isPossible)) break;
        for (int y=0; y<M; y++) {
            if (board[x][y] == '*' && not(isChecked[x][y])) {
                isPossible = false;
                break;
            }
        }
    }

    if (not(isPossible))
        cout << -1 << endl;
    else {
        cout << k << endl;
        for (Cross c : crosses) {
            cout << c.x << ' ' << c.y << ' ' << c.s << endl;
        }
    }
}

// Helper Functions
bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

int getMaxS(int x, int y)
{
    int maxS = INF;
    for (int i=0; i<4; i++) {
        int s = 0;
        int ax = x + dx[i];
        int ay = y + dy[i];
        while (isValid(ax, ay) && board[ax][ay] == '*') {
            s++;
            ax += dx[i];
            ay += dy[i];
        }
        maxS = min(maxS, s);
    }
    return maxS;
}

void putCross(int x, int y, int s)
{
    isChecked[x][y] = true;
    for (int i=1; i<=s; i++) {
        isChecked[x+i][y] = true;
        isChecked[x-i][y] = true;
        isChecked[x][y+i] = true;
        isChecked[x][y-i] = true;
    }
}
