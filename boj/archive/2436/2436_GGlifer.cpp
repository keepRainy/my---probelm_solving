//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cmath>
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
    long G, L;
    cin >> G >> L;

    // Process
    long ab = L/G;
    long A, B;
    for (long i=sqrt(ab); i>=1; i--) {
        if (ab % i == 0 && gcd(i, ab/i) == 1) {
            A = i * G;
            B = ab / i * G;
            break;
        }
    }

    // Control : Output
    cout << A << ' ' << B << endl;
}

// Helper Functions
/* None */

