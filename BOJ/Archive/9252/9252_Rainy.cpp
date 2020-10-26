//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <cstring>
#include <algorithm>

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
    string u; cin >> u;
    string v; cin >> v;

    // Process
    int lu = u.length();
    int lv = v.length();
    int dp[lu+1][lv+1];
    memset(dp, 0, sizeof(dp));

    for (int i=1; i<=lu; i++) {
        char cu = u[i-1];
        for (int j=1; j<=lv; j++) {
            char cv = v[j-1];
            if (cu == cv) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string LCS;
    int y = lu, x = lv;
    while (y > 0 && x > 0) {
        if (dp[y][x] == dp[y-1][x])
            y--;
        else if (dp[y][x] == dp[y][x-1])
            x--;
        else {
            LCS.insert(LCS.begin(), u[y-1]);
            y--; x--;
        }
    }

    // Control : Output
    cout << dp[lu][lv] << endl;
    cout << LCS << endl;
}

// Helper Functions
/* None */

