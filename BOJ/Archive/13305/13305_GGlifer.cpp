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
#define INF (1000000000+1)

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int D[N-1];
    for (int i=0; i<N-1; i++)
        cin >> D[i];
    int P[N];
    for (int i=0; i<N; i++)
        cin >> P[i];

    // Process
    long ans = 0;
    int mn = INF;
    for (int i=0; i<N-1; i++) {
        mn = min(mn, P[i]);
        ans += (long)mn * D[i];
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

