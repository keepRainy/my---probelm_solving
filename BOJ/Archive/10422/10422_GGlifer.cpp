//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>

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

    // Process
    long D[5000+1];
    memset(D, 0, sizeof(D));
    D[0] = 1;
    for (int i=2; i<=5000; i+=2) {
        for (int j=0; j<=i-2; j+=2) {
            D[i] += D[j] * D[i-2-j];
            D[i] %= 1'000'000'007;
        }
    }

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int L; cin >> L;

        // Control : Output
        cout << D[L] << endl;
    }
}

// Helper Functions
/* None */

