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
int puzzle[9][9];
bool isUsed[10][10];
bool checkRow[9][10];
bool checkCol[9][10];
bool checkBox[3][3][10];
int dy[2] = {+1, 0};
int dx[2] = {0, +1};

// Set up : Functions Declaration
bool isValid(int y, int x);
void setUp(int cy, int cx, int u, int ny, int nx, int v);
void getBack(int cy, int cx, int u, int ny, int nx, int v);
bool go(int c);

int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int tc = 0, N;
    while (true) {
        cin >> N;
        if (N == 0) break;
        tc++;

        // Reset
        memset(puzzle, 0, sizeof(puzzle));
        memset(isUsed, false, sizeof(isUsed));
        memset(checkRow, false, sizeof(checkRow));
        memset(checkCol, false, sizeof(checkCol));
        memset(checkBox, false, sizeof(checkBox));

        // Set up : Input
        for (int i=0; i<N; i++) {
            int U, V;
            string LU, LV;
            cin >> U >> LU >> V >> LV;
            puzzle[LU[0]-'A'][LU[1]-'1'] = U;
            puzzle[LV[0]-'A'][LV[1]-'1'] = V;
            isUsed[U][V] = isUsed[V][U] = true;
        }
        for (int i=1; i<=9; i++) {
            string P; cin >> P;
            puzzle[P[0]-'A'][P[1]-'1'] = i;
        }

        // Process
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                int v = puzzle[i][j];
                checkRow[i][v] = true;
                checkCol[j][v] = true;
                checkBox[i/3][j/3][v] = true;
            }
        }

        go(0);

        // Control : Output
        cout << "Puzzle " << tc << endl;
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << puzzle[i][j];
            } cout << endl;
        }
    }
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < 9 && x >= 0 && x < 9;
}

bool isPossible(int y, int x, int n)
{
    if (checkRow[y][n]) return false;
    if (checkCol[x][n]) return false;
    if (checkBox[y/3][x/3][n]) return false;
    return true;
}

void setUp(int cy, int cx, int u, int ny, int nx, int v)
{
    puzzle[cy][cx] = u;
    puzzle[ny][nx] = v;
    checkRow[cy][u] = true;
    checkCol[cx][u] = true;
    checkBox[cy/3][cx/3][u] = true;
    checkRow[ny][v] = true;
    checkCol[nx][v] = true;
    checkBox[ny/3][nx/3][v] = true;
    isUsed[u][v] = isUsed[v][u] = true;
}

void getBack(int cy, int cx, int u, int ny, int nx, int v)
{
    puzzle[cy][cx] = 0;
    puzzle[ny][nx] = 0;
    checkRow[cy][u] = false;
    checkCol[cx][u] = false;
    checkBox[cy/3][cx/3][u] = false;
    checkRow[ny][v] = false;
    checkCol[nx][v] = false;
    checkBox[ny/3][nx/3][v] = false;
    isUsed[u][v] = isUsed[v][u] = false;
}

bool go(int c)
{
    if (c == 81) return true;

    int cy = c / 9;
    int cx = c % 9;
    if (puzzle[cy][cx] != 0) {
        return go(c+1);
    }

    for (int i=0; i<2; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (not(isValid(ny, nx))) continue;
        if (puzzle[ny][nx] != 0) continue; 

        for (int u=1; u<=9; u++) {
            for (int v=1; v<=9; v++) {
                if (u == v) continue;
                if (isUsed[u][v]) continue;
                if (not(isPossible(cy, cx, u))) continue;
                if (not(isPossible(ny, nx, v))) continue;

                setUp(cy, cx, u, ny, nx, v);
                if (go(c+1)) {
                    return true;
                }
                getBack(cy, cx, u, ny, nx, v);
            }
        }
    }

    return false;
}
