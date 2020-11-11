//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int R, C;
    cin >> R >> C;
    char B[R][C];
    for (int i=0; i<R; i++)
        for (int j=0; j<C; j++)
            cin >> B[i][j];

    // Process
    bool isThereBlindLane = false;
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            if (B[i][j] == '.') {
                int cnt = 0;
                for (int k=0; k<4; k++) {
                    int ay = i + dy[k];
                    int ax = j + dx[k];
                    if (ay >= 0 && ay < R && ax >= 0 && ax < C) {
                        if (B[ay][ax] == '.') {
                            cnt++;
                        }
                    }
                }
                if (cnt < 2) {
                    isThereBlindLane = true;
                    break;
                }
            }
        }
    }

    // Control : Output
    cout << ((isThereBlindLane) ? 1 : 0) << endl;
}

// Helper Functions
/* None */

