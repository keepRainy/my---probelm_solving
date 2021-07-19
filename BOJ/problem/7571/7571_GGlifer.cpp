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
    int N, M;
    cin >> N >> M;
    vector<int> Y(M), X(M);
    for (int i=0; i<M; i++)
        cin >> X[i] >> Y[i];

    // Process
    sort(Y.begin(), Y.end());
    sort(X.begin(), X.end());
    int ans = 0, my = Y[M/2], mx = X[M/2];
    for (int y : Y) {
        ans += abs(my-y);
    }
    for (int x : X) {
        ans += abs(mx-x);
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

