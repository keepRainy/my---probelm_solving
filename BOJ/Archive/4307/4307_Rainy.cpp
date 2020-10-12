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
    int T; cin >> T;

    while (T--) {
        int L, N;
        cin >> L >> N;
        int P[N];
        for (int i=0; i<N; i++)
            cin >> P[i];

        // Process
        int fast = min(P[0], L-P[0]);
        int slow = max(P[0], L-P[0]);
        for (int i=1; i<N; i++) {
            fast = max(fast, min(P[i], L-P[i]));
            slow = max(slow, max(P[i], L-P[i]));
        }

        // Control : Output
        cout << fast << ' ' << slow << endl;
    }
}

// Helper Functions
/* None */

