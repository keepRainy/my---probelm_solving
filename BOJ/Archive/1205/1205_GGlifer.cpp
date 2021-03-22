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
    int N, S, P;
    cin >> N >> S >> P;
    vector<int> L(P, -1);
    for (int i=0; i<N; i++)
        cin >> L[i];

    // Process
    auto pos = lower_bound(L.rbegin(), L.rend(), S);
    int idx = P - (pos - L.rbegin());

    int ans = -1;
    if (idx < P) {
        L[idx] = S;
        int G[P];
        for (int i=0; i<P; i++) {
            G[i] = i+1;
            if (i > 0 && L[i] == L[i-1]) {
                G[i] = G[i-1];
            }
        }
        ans = G[idx];
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

