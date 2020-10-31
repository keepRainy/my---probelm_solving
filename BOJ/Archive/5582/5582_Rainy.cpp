//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>
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
    string u; cin >> u;
    string v; cin >> v;

    // Process
    int lu = u.length();
    int lv = v.length();

    int dp[lu+1][lv+1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i=1; i<=lu; i++) {
        for (int j=1; j<=lv; j++) {
            if (u[i-1] == v[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

