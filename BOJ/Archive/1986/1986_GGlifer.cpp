//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
char board[1000][1000];
bool isSafe[1000][1000];
int dqy[8] = {-1, -1, -1,  0,  0, +1, +1, +1};
int dqx[8] = {-1,  0, +1, -1, +1, -1,  0, +1};
int dky[8] = {-2, -2, -1, -1, +1, +1, +2, +2};
int dkx[8] = {-1, +1, -2, +2, -2, +2, -1, +1};

// Set up : Functions Declaration
bool isValid(int y, int x);
void checkQueen(int y, int x);
void checkKnight(int y, int x);
void checkPawn(int y, int x);

int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;
    memset(board, ' ', sizeof(board));
    int NQ; cin >> NQ;
    for (int i=0; i<NQ; i++) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = 'Q';
    }
    int NK; cin >> NK;
    for (int i=0; i<NK; i++) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = 'K';
    }
    int NP; cin >> NP;
    for (int i=0; i<NP; i++) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = 'P';
    }

    // Process
    memset(isSafe, true, sizeof(isSafe));
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (board[i][j] != ' ') {
                switch (board[i][j]) {
                    case 'Q': checkQueen(i, j); break;
                    case 'K': checkKnight(i, j); break;
                    case 'P': checkPawn(i, j); break;
                    default: throw runtime_error("Invalid Value");
                }
            }
        }
    }

    // Control : Output
    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (isSafe[i][j]) { ans++; }
        }
    }
    cout << ans << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}

void checkQueen(int y, int x)
{
    isSafe[y][x] = false;
    for (int i=0; i<8; i++) {
        int ay = y + dqy[i];
        int ax = x + dqx[i];
        while (isValid(ay, ax) && board[ay][ax] == ' ') {
            isSafe[ay][ax] = false;
            ay += dqy[i];
            ax += dqx[i];
        }
    }
}

void checkKnight(int y, int x)
{
    isSafe[y][x] = false;
    for (int i=0; i<8; i++) {
        int ay = y + dky[i];
        int ax = x + dkx[i];
        if (isValid(ay, ax) && board[ay][ax] == ' ') {
            isSafe[ay][ax] = false;
        }
    }
}

void checkPawn(int y, int x)
{
    isSafe[y][x] = false;
}
