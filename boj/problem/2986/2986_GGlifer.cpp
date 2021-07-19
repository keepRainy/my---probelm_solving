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

    // Process
    int counter = N-1;
    for (int i=2; i*i<=N; i++) {
        if (N%i == 0) {
            counter = N-N/i;
            break;
        }
    }

    // Control : Output
    cout << counter << endl;
}

// Helper Functions
/* None */

