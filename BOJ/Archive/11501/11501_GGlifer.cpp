//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>

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
        int A[N];
        for (int i=0; i<N; i++)
            cin >> A[i];

        // Process
        long ans = 0;
        int mx = -1;
        for (int i=N-1; i>=0; i--) {
            mx = max(mx, A[i]);
            ans += mx-A[i];
        }

        // Control : Output
        cout << ans << endl;
    }
}

// Helper Functions
/* None */

