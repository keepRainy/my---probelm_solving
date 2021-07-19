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
    int C[10000+1] = {0, };

    // Process
    for (int i=0; i<N; i++) {
        int n; cin >> n;
        C[n]++;
    }

    // Control : Output
    for (int i=1; i<=10000; i++) {
        for (int j=0; j<C[i]; j++) {
            cout << i << endl;
        }
    }
}

// Helper Functions
/* None */

