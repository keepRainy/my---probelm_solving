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
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int C, P;
    cin >> C >> P;
    int H[C];
    for (int i=0; i<C; i++) {
        cin >> H[i];
    }

    // Process
    int ans[7+1];

    ans[1] = 0;
    ans[1] += C;
    if (C >= 4) {
        for (int i=0; i<C-3; i++) {
            if (H[i] == H[i+1] && H[i+1] == H[i+2] && H[i+2] == H[i+3]) {
                ans[1]++;
            }
        }
    }

    ans[2] = 0;
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i] == H[i+1]) {
                ans[2]++;
            }
        }
    }

    ans[3] = 0;
    if (C >= 3) {
        for (int i=0; i<C-2; i++) {
            if (H[i] == H[i+1] && H[i+1]+1 == H[i+2]) {
                ans[3]++;
            }
        }
    }
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i] == H[i+1]+1) {
                ans[3]++;
            }
        }
    }

    ans[4] = 0;
    if (C >= 3) {
        for (int i=0; i<C-2; i++) {
            if (H[i] == H[i+1]+1 && H[i+1] == H[i+2]) {
                ans[4]++;
            }
        }
    }
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i]+1 == H[i+1]) {
                ans[4]++;
            }
        }
    }

    ans[5] = 0;
    if (C >= 3) {
        for (int i=0; i<C-2; i++) {
            if (H[i] == H[i+1] && H[i+1] == H[i+2]) {
                ans[5]++;
            }
        }
    }
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i] == H[i+1]+1) {
                ans[5]++;
            }
        }
    }
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i]+1 == H[i+1]) {
                ans[5]++;
            }
        }
    }
    if (C >= 3) {
        for (int i=0; i<C-2; i++) {
            if (H[i] == H[i+1]+1 && H[i+1]+1 == H[i+2]) {
                ans[5]++;
            }
        }
    }

    ans[6] = 0;
    if (C >= 3) {
        for (int i=0; i<C-2; i++) {
            if (H[i] == H[i+1] && H[i+1] == H[i+2]) {
                ans[6]++;
            }
        }
    }
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i] == H[i+1]) {
                ans[6]++;
            }
        }
    }
    if (C >= 3) {
        for (int i=0; i<C-2; i++) {
            if (H[i]+1 == H[i+1] && H[i+1] == H[i+2]) {
                ans[6]++;
            }
        }
    }
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i] == H[i+1]+2) {
                ans[6]++;
            }
        }
    }

    ans[7] = 0;
    if (C >= 3) {
        for (int i=0; i<C-2; i++) {
            if (H[i] == H[i+1] && H[i+1] == H[i+2]) {
                ans[7]++;
            }
        }
    }
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i] == H[i+1]) {
                ans[7]++;
            }
        }
    }
    if (C >= 3) {
        for (int i=0; i<C-2; i++) {
            if (H[i] == H[i+1] && H[i+1] == H[i+2]+1) {
                ans[7]++;
            }
        }
    }
    if (C >= 2) {
        for (int i=0; i<C-1; i++) {
            if (H[i]+2 == H[i+1]) {
                ans[7]++;
            }
        }
    }

    // Control : Output
    cout << ans[P] << endl;
}

// Helper Functions
/* None */

