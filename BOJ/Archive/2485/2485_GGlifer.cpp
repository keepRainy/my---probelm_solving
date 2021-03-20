//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <numeric>

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
    int P[N];
    for (int i=0; i<N; i++)
        cin >> P[i];

    // Process
    sort(P, P+N);
    int dst = P[1]-P[0];
    for (int i=2; i<N; i++) {
        dst = gcd(dst, P[i]-P[i-1]);
    }
    int ans = (P[N-1]-P[0])/dst+1-N;

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

