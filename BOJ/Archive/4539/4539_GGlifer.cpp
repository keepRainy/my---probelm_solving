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

    while (N--) {
        int X; cin >> X;

        // Process
        for (int i=10; i<X; i*=10) {
            if (X % i / (i/10) >= 5) {
                X = (X/i + 1) * i;
            } else {
                X = X/i * i;
            }
        }

        // Control : Output
        cout << X << endl;
    }
}

// Helper Functions
/* None */
