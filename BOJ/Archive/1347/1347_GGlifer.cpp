//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <set>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int dy[4] = {-1, 0, 0, +1};
int dx[4] = {0, -1, +1, 0};
enum { N, L, R, S };
enum { RL, RR };
int D[4][2] = { {L, R}, {S, N}, {N, S}, {R, L} };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int L; cin >> L;
    string C; cin >> C;

    // Process
    int cy = 0, cx = 0;
    int lly, ury, llx, urx;
    lly = ury = cy;
    llx = urx = cx;
    set<pair<int,int>> M;
    M.insert({cy, cx});
    int d = S;
    for (char c : C) {
        switch (c) {
            case 'R': d = D[d][RR]; break;
            case 'L': d = D[d][RL]; break;
            case 'F':
                cy += dy[d], cx += dx[d];
                M.insert({cy, cx});
                lly = min(lly, cy), ury = max(ury, cy);
                llx = min(llx, cx), urx = max(urx, cx);
                break;
            default: throw runtime_error("Invalid Command");
        }
    }

    int r = ury-lly+1;
    int c = urx-llx+1;

    char A[r][c];
    memset(A, '#', sizeof(A));
    for (auto [y, x] : M) {
        A[y-lly][x-llx] = '.';
    }

    // Control : Output
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            cout << A[i][j];
        } cout << endl;
    }
}

// Helper Functions
/* None */
