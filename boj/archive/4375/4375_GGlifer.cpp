//
//  Codeforces
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
    int N;
    while (cin >> N) {

        // Process
        int len = 1, res = 1 % N;
        while (res != 0) {
            res *= 10;
            res += 1;
            res %= N;
            len++;
        }

        // Control : Output
        cout << len << endl;
    }
}

// Helper Functions
/* None */

