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
    int A, B;
    cin >> A >> B;

    // Process
    A--, B--;
    int n = 1;
    int ans = 0;
    while (true) {
        int li = (n-1)*n/2;
        int ri = n*(n+1)/2-1;
        if (ri < A) { n++; continue; }
        if (li > B) break;
        int sli = max(A, li);
        int sri = min(B, ri);
        ans += (sri-sli+1)*n++;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

