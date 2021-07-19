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
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    sort(A, A+N);

    // Control : Output
    cout << A[(N-1)/2] << endl;
}

// Helper Functions
/* None */

