//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
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
    int N; cin >> N;
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    int dp[N];
    fill(dp, dp+N, 1);
    for (int i=1; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    // Control : Output
    cout << *max_element(dp, dp+N) << endl;
}

// Helper Functions
/* None */

