//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <map>

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
    string R; cin >> R;

    // Process
    map<char,char> P;
    P['B'] = 'J';
    P['O'] = 'B';
    P['J'] = 'O';

    int dp[N];
    fill(dp, dp+N, -1);
    dp[0] = 0;

    for (int i=1; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (R[j] == P[R[i]] && dp[j] != -1) {
                if (dp[i] == -1 || dp[i] > dp[j] + (i-j)*(i-j)) {
                    dp[i] = dp[j] + (i-j)*(i-j);
                }
            }
        }
    }

    // Control : Output
    cout << dp[N-1] << endl;
}

// Helper Functions
/* None */

