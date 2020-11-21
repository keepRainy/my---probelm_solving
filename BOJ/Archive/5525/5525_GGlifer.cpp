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

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int M; cin >> M;
    string S; cin >> S;

    // Process
    int dp[M];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i=2; i<M; i++) {
        if (S[i] == 'I' && S[i-1] == 'O' && S[i-2] == 'I') {
            dp[i] = dp[i-2] + 1;
            if (dp[i] >= N) {
                ans++;
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */
