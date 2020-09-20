//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>

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
    string C = to_string(A);
    sort(C.begin(), C.end(), greater<>());

    int ans = -1;
    do {
        if (C.front() == '0') continue;

        if (stoi(C) <= B) {
            ans = stoi(C);
            break;
        }
    } while (prev_permutation(C.begin(), C.end()));

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

