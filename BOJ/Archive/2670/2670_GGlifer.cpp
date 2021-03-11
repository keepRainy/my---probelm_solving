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
    int N; cin >> N;
    double A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    double dp[N];
    dp[0] = A[0];
    double ans = dp[0];
    for (int i=1; i<N; i++) {
        dp[i] = A[i] * ((dp[i-1] > 1) ? dp[i-1] : 1);
        ans = max(ans, dp[i]);
    }

    // Control : Output
    cout << fixed;
    cout.precision(3);
    cout << ans << endl;
}

// Helper Functions
/* None */

