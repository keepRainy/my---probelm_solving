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
#define WIN true
#define LOSE false

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
    bool dp[N+1];
    memset(dp, LOSE, sizeof(dp));
    dp[1] = dp[3] = dp[4] = WIN;

//    for (int i=1; i<=N; i++) {
//        if (dp[i] == LOSE) {
//            if (i+1 <= N) { dp[i+1] = WIN; }
//            if (i+3 <= N) { dp[i+3] = WIN; }
//            if (i+4 <= N) { dp[i+4] = WIN; }
//        }
//    }

    for (int i=5; i<=N; i++) {
        if (dp[i-1] == LOSE || dp[i-3] == LOSE || dp[i-4] == LOSE) {
            dp[i] = WIN;
        }
    }

    // Control : Output
    cout << ((dp[N] == WIN) ? "SK " : "CY") << endl;
}

// Helper Functions
/* None */

