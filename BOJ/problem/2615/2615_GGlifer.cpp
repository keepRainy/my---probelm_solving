//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N = 19;
int B[19+1][19+1];
bool V[19+1][19+1][4];
int dy[4] = {+1, +1, 0, +1};
int dx[4] = {0, +1, +1, -1};

// Set up : Functions Declaration
int isWon(int y, int x);
bool isValid(int y, int x);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            cin >> B[i][j];

    // Process
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (B[i][j] != 0) {
                int res = isWon(i, j);

                // Control : Output
                if (res != -1) {
                    cout << B[i][j] << endl;
                    cout << ((res == 3) ? i+4 : i);
                    cout << ' ';
                    cout << ((res == 3) ? j-4 : j);
                    exit(0);
                }
            }
        }
    }

    // Control : Output
    cout << 0 << endl;
}

// Helper Functions
int isWon(int y, int x)
{
    for (int i=0; i<4; i++) {
        if (V[y][x][i]) continue;
        V[y][x][i] = true;

        int cnt = 1;

        int ny = y + dy[i];
        int nx = x + dx[i];
        while (isValid(ny, nx) && B[ny][nx] == B[y][x] && not(V[ny][nx][i])) {
            cnt++;
            V[ny][nx][i] = true;
            ny += dy[i];
            nx += dx[i];
        }

        if (cnt == 5) return i;
    }
    return -1;
}

bool isValid(int y, int x)
{
   return y >= 1 && y <= N && x >= 1 && x <= N;
}
