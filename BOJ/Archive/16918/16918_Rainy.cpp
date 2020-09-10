//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int R, C, N;
char board[200][200];
int cnt[200][200];
struct Point { int y, x; };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
bool isValid(int y, int x);
void set();
void bomb();


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> R >> C >> N;
    memset(cnt, -1, sizeof(cnt));
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'O') {
                cnt[i][j] = 1;
            }
        }
    }

    // Process
    int T = 1;
    if (N > 1) {
        while (true) {
            set(); T++;
            if (T == N) break;

            bomb(); T++;
            if (T == N) break;
        }
    }

    // Control : Output
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cout << ((cnt[i][j] != -1) ? 'O' : '.');
        } cout << endl;
    }
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < R && x >= 0 && x < C;
}

void set()
{
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cnt[i][j]++;
        }
    }
}

void bomb()
{
    vector<Point> bombs;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cnt[i][j]++;
            if (cnt[i][j] == 3) {
                bombs.push_back({i, j});
            }
        }
    }

    for (Point b : bombs) {
        cnt[b.y][b.x] = -1;
        for (int i=0; i<4; i++) {
            int ay = b.y + dy[i];
            int ax = b.x + dx[i];
            if (isValid(ay, ax)) {
                cnt[ay][ax] = -1;
            }
        }
    }
}
