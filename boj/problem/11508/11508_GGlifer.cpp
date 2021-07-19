//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
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
    int C[N];
    for (int i=0; i<N; i++)
        cin >> C[i];

    // Process
    sort(C, C+N, greater<>());
    long ans = accumulate(C, C+N, (long)0);
    for(int i=2; i<N; i+=3) {
        ans -= C[i];
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

