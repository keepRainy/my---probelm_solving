//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int R, C, T;
int board[50][50];
struct Point { int y, x; };
vector<Point> Cleaner;
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
#define CLEANER (-1)

// Set up : Functions Declaration
bool isValid(int y, int x);
void spread();
void clean();


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> R >> C >> T;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                Cleaner.push_back({i, j});
            }
        }
    }

    // Process
    while (T--) {
        spread();
        clean();
    }

    int ans = 0;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] > 0) {
                ans += board[i][j];
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < R && x >= 0 && x < C;
}

void spread()
{
    int update[50][50];
    memset(update, 0, sizeof(update));
    Point n = Cleaner.front(), s = Cleaner.back();
    update[n.y][n.x] = CLEANER;
    update[s.y][s.x] = CLEANER;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (board[i][j] > 0) {
                int res = board[i][j];
                int amt = res / 5;
                int cnt = 0;
                for (int k=0; k<4; k++) {
                    int ay = i + dy[k];
                    int ax = j + dx[k];
                    if (isValid(ay, ax) && board[ay][ax] != CLEANER) {
                        cnt++;
                        update[ay][ax] += amt;
                    }
                }
                update[i][j] += res - cnt * amt;
            }
        }
    }

    memcpy(board, update, sizeof(board));
}


void clean()
{
    Point n = Cleaner.front();
    int ny = n.y, nx = n.x;
    for (int i=ny-2; i>=0; i--)
        board[i+1][0] = board[i][0];
    for (int j=1; j<C; j++)
        board[0][j-1] = board[0][j];
    for (int i=1; i<=ny; i++)
        board[i-1][C-1] = board[i][C-1];
    for (int j=C-2; j>=1; j--)
        board[ny][j+1] = board[ny][j];
    board[ny][nx+1] = 0;

    Point s = Cleaner.back();
    int sy = s.y, sx = s.x;
    for (int i=sy+2; i<R; i++)
        board[i-1][0] = board[i][0];
    for (int j=1; j<C; j++)
        board[R-1][j-1] = board[R-1][j];
    for (int i=R-2; i>=sy; i--)
        board[i+1][C-1] = board[i][C-1];
    for (int j=C-2; j>=1; j--)
        board[sy][j+1] = board[sy][j];
    board[sy][sx+1] = 0;
}
