//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
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
    int N; cin >> N;
    int W[N];
    for (int i=0; i<N; i++)
        cin >> W[i];

    // Process
    sort(W, W+N);
    int ans = -1;
    for (int i=0; i<N; i++) {
        ans = max(ans, W[i]*(N-i));
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

