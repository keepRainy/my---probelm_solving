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
int R, C;
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
    cin >> R >> C;
    char A[R][C];
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            cin >> A[i][j];

    // Process
    char B[R][C];
    memcpy(B, A, sizeof(B));

    int uly = R, ulx = C, lry = -1, lrx = -1;

    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (A[i][j] == 'X') {
                int sea = 0;
                for (int k=0; k<4; k++) {
                    int ay = i + dy[k];
                    int ax = j + dx[k];
                    if (not(isValid(ay, ax)) || A[ay][ax] == '.') {
                        sea++;
                    }
                }
                if (sea >= 3) {
                    B[i][j] = '.';
                } else {
                    uly = min(uly, i);
                    ulx = min(ulx, j);
                    lry = max(lry, i);
                    lrx = max(lrx, j);
                }
            }
        }
    }

    // Control : Output
    for (int i=uly; i<=lry; i++) {
        for (int j=ulx; j<=lrx; j++) {
            cout << B[i][j];
        } cout << endl;
    }
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < R && x >= 0 && x < C;
}
