//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
int A[1000+1];
int dp[1000+1];

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> A[i];

    // Process
    for (int i=1; i<=N; i++) {
        int mx, mn;
        mx = mn = A[i];
        dp[i] = dp[i-1];
        for (int j=i; j>=1; j--) {
            mx = max(mx, A[j]);
            mn = min(mn, A[j]);
            dp[i] = max(dp[i], mx-mn+dp[j-1]);
        }
    }

    // Control : Output
    cout << dp[N] << endl;
}

// Helper Functions
/* None */
