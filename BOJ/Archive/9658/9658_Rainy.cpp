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
    dp[1] = LOSE;
    for (int i=1; i<=N; i++) {
        if (dp[i] == LOSE) {
            if (i+1 <= N) { dp[i+1] = WIN; }
            if (i+2 <= N) { dp[i+2] = WIN; }
            if (i+3 <= N) { dp[i+3] = WIN; }
        }
    }

    // Control : Output
    cout << ((dp[N] == WIN) ? "SK" : "CY") << endl;

    // switch (--N % 7) {
    //     case 0:
    //     case 2:
    //         cout << "CY" << endl;
    //         break;
    //     case 1:
    //     case 3:
    //     case 4:
    //     case 5:
    //     case 6:
    //         cout << "SK" << endl;
    //         break;
    // }
}

// Helper Functions
