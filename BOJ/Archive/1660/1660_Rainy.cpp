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
    int dp[N+1];
    for (int i=0; i<=N; i++) {
        dp[i] = i;
    }

    int i, j, k;
    i = j = k = 1;
    while (k <= N) {
        for (int n=1; n<=N; n++) {
            if (n >= k) {
                dp[n] = min(dp[n], dp[n-k]+1);
            }
        }

        i += 1;
        j += i;
        k += j;
    }

    // Control : Output
    cout << dp[N] << endl;
}

// Helper Functions
/* None */

