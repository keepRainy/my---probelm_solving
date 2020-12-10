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
    int N, K;
    cin >> N >> K;
    string D; cin >> D;

    // Process
    string A;
    A.push_back(D[0]);
    int len = D.length();
    int i = 1;
    while (i < len) {
        while (K > 0 && not(A.empty()) && D[i] > A.back()) {
            A.pop_back();
            K--;
        }
        A.push_back(D[i]);
        i++;
    }

    while (K--) {
        A.pop_back();
    }

    // Control : Output
    cout << A << endl;
}

// Helper Functions
/* None */

