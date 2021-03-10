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
    int N; cin >> N;
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    int ans = 0;
    for (int i=N-2; i>=0; i--) {
        if (A[i] >= A[i+1]) {
            ans += A[i] - (A[i+1]-1);
            A[i] = A[i+1]-1;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

