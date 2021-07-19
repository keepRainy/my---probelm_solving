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
long getGCD(long n, long m);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    long x, y;
    cin >> x >> y;

    // Process
    long gcd = getGCD(x, y);
    long cox = x / gcd;
    long coy = y / gcd;

    // Control : Output
    cout << gcd * (cox+coy-1) << endl;
}

// Helper Functions
long getGCD(long n, long m)
{
    while (m) {
        long r = n % m;
        n = m;
        m = r;
    } return n;
}
