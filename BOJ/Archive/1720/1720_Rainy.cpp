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
    int N; cin >> N;

    // Process
    int dp1[N+1];
    memset(dp1, 0, sizeof(dp1));
    dp1[0] = dp1[1] = 1;
    for (int i=2; i<=N; i++) {
        dp1[i] = dp1[i-1] + 2*dp1[i-2];
    }

    int dp2[N+1];
    memset(dp2, 0, sizeof(dp2));
    for (int i=1; i<=N; i+=2) {
        dp2[i] = dp1[(i-1)/2];
    }
    for (int i=2; i<=N; i+=2) {
        dp2[i] = dp1[i/2] + 2*dp1[(i-2)/2];
    }

    int ans = (dp1[N] + dp2[N]) / 2;

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

