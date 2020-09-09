//
//  BOJ
//  ver.C++
//
//  Created by Rainy
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
    long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    // Process
    long ans = 0;
    if (2*C <= A+B) {
        long Z = min(X, Y);
        ans += Z * 2*C;
        X -= Z;
        Y -= Z;
        if (X > 0) {
            ans += (2*C <= A) ? X * 2*C : X * A;
        }
        if (Y > 0) {
            ans += (2*C <= B) ? Y * 2*C : Y * B;
        }
    }
    else {
        ans += X * A;
        ans += Y * B;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */
