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
        int N; cin >> N;
        int L[N];
        for (int i=0; i<N; i++) {
            cin >> L[i];
        }

        // Process
        sort(L, L+N);
        int ans = -1;
        for (int i=0; i<N-2; i++) {
            ans = max(ans, abs(L[i]-L[i+2]));
        }

        // Control : Output
        cout << ans << endl;
    }
}

// Helper Functions
/* None */

