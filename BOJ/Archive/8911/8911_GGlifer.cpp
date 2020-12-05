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
enum { S, E, W, N };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
enum { L, R };
int cd[4][2] = {
        {E, W}, /* S */
        {N, S}, /* E */
        {S, N}, /* W */
        {W, E}  /* N */
};

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        string P; cin >> P;

        // Process
        int cy = 0, cx = 0, dir = N;
        int lly, llx, ury, urx;
        lly = ury = cy;
        llx = urx = cx;

        for (char cmd : P) {
            switch (cmd) {
                case 'F':
                    cy += dy[dir];
                    cx += dx[dir];
                    break;
                case 'B':
                    cy -= dy[dir];
                    cx -= dx[dir];
                    break;
                case 'L':
                    dir = cd[dir][L];
                    break;
                case 'R':
                    dir = cd[dir][R];
                    break;
                default:
                    throw invalid_argument("Invalid Command");
            }

            lly = min(lly, cy);
            ury = max(ury, cy);
            llx = min(llx, cx);
            urx = max(urx, cx);
        }

        // Control : Output
        int w = urx - llx;
        int h = ury - lly;
        cout << w*h << endl;
    }
}

// Helper Functions
/* None */

