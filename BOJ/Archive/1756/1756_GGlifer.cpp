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
    int D, N;
    cin >> D >> N;
    int OR[D], PR[N];
    for (int i=0; i<D; i++)
        cin >> OR[i];
    for (int i=0; i<N; i++)
        cin >> PR[i];

    // Process
    for (int i=1; i<D; i++) {
        OR[i] = min(OR[i], OR[i-1]);
    }

    int idx = 0;
    int ans = -1;
    for (int i=D-1; i>=0 && idx<N; i--) {
        if (OR[i] >= PR[idx]) {
            ans = i+1;
            idx++;
        }
    }

    if (idx != N) {
        ans = 0;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

