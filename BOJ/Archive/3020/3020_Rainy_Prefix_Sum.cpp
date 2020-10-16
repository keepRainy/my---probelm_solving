//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <cstring>

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
    int N, H;
    cin >> N >> H;
    int U[H+1], D[H+1];
    memset(U, 0, sizeof(U));
    memset(D, 0, sizeof(D));
    for (int i=0; i<N/2; i++) {
        int u, d;
        cin >> u >> d;
        U[u]++; D[d]++;
    }

    // Process
    for (int i=H-1; i>=1; i--) {
        U[i] += U[i+1];
        D[i] += D[i+1];
    }

    int ans1 = -1, ans2 = 0;
    for (int i=1; i<=H; i++) {
        int cnt = U[i] + D[H-i+1];
        if (ans1 == -1 || ans1 > cnt) {
            ans1 = cnt;
            ans2 = 1;
        } else if (ans1 == cnt) {
            ans2++;
        }
    }

    // Control : Output
    cout << ans1 << ' ' << ans2 << endl;
}

// Helper Functions
/* None */

