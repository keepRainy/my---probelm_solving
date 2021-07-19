//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
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
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    int dp[N+1];
    memset(dp, 0, sizeof(dp));

    int mx = -1;
    for (int i=0; i<N; i++) {
        dp[A[i]] = dp[A[i]-1] + 1;
        mx = max(mx, dp[A[i]]);
    }

    // Control : Output
    cout << N-mx << endl;
}

// Helper Functions
/* None */

