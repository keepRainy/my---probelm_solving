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
    int H, W;
    cin >> H >> W;
    int A[W];
    for (int i=0; i<W; i++)
        cin >> A[i];

    // Process
    int LMH[W], RMH[W];
    LMH[0] = 0;
    for (int i=1; i<=W-1; i++) {
        LMH[i] = max(A[i-1], LMH[i-1]);
    }
    RMH[W-1] = 0;
    for (int i=W-2; i>=0; i--) {
        RMH[i] = max(A[i+1], RMH[i+1]);
    }

    int ans = 0;
    for (int i=1; i<=W-2; i++) {
        int lmh = LMH[i], rmh = RMH[i];
        ans += max(0, min(lmh, rmh)-A[i]);
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

