//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <cstring>
#include <numeric>

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
    int D1, D2;
    cin >> D1 >> D2;

    // Process
    bool isSeat[D2+1][D2];
    memset(isSeat, false, sizeof(isSeat));
    int ans = 0;
    for (int i=D1; i<=D2; i++) {
        for (int j=1; j<=i; j++) {
            int g = gcd(i, j);
            if (not(isSeat[j/g][i/g])) {
                isSeat[j/g][i/g] = true;
                ans++;
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

