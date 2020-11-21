//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
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
    int K; cin >> K;
    vector<int> P(N);
    for (int i=0; i<N; i++)
        cin >> P[i];

    // Process
    sort(P.begin(), P.end());
    vector<int> D(N-1);
    for (int i=0; i<N-1; i++) {
        D[i] = P[i+1] - P[i];
    }
    sort(D.begin(), D.end());
    int ans = 0;
    for (int i=0; i<N-K; i++) {
        ans += D[i];
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

