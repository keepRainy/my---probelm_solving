//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
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
    string S; cin >> S;

    // Process
    int C[26] = {0, };
    for (char c : S) {
        C[c-'A']++;
    }

    string M;
    for (int i=0; i<26; i++) {
        if (C[i]%2 == 1) {
            M.push_back('A'+i);
        }
    }

    string A;
    if (M.length() <= 1) {
        string F;
        for (int i=0; i<26; i++) {
            F += string(C[i]/2, 'A'+i);
        } string B(F.rbegin(), F.rend());
        A = F + M + B;
    }

    // Control : Output
    if (M.length() > 1)
        cout << "I'm Sorry Hansoo" << endl;
    else
        cout << A << endl;
}

// Helper Functions
/* None */

