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
    int A[N+1];
    for (int i=1; i<=N; i++)
        cin >> A[i];

    // Process
    long ans = 0;
    sort(A+1, A+(N+1));
    for (int i=1; i<=N; i++) {
        ans += abs(A[i]-i);
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

