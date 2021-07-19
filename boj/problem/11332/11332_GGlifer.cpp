//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
double log_f(double n);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int C; cin >> C;

    while (C--) {
        string S; double N, T, L;
        cin >> S >> N >> T >> L;

        // Process
        L *= 100'000'000;
        L /= T;

        bool isPossible = true;
        if (S == "O(N)" && N > L) { isPossible = false; }
        if (S == "O(N^2)" && N*N > L) { isPossible = false; }
        if (S == "O(N^3)" && N*N*N > L) { isPossible = false; }
        if (S == "O(2^N)" && N > log2(L)) { isPossible = false; }
        if (S == "O(N!)" && N > log_f(L)) { isPossible = false; }

        // Control : Output
        cout << ((isPossible) ? "May Pass." : "TLE!") << endl;
    }
}

// Helper Functions
double log_f(double n)
{
    int i = 1; double v = 1;
    while ((v *= ++i) <= n);
    return i-1;
}
