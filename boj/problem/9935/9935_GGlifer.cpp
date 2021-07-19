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
    string S; cin >> S;
    string W; cin >> W;

    // Process
    int SL = S.length();
    int WL = W.length();

    string A;
    for (int i=0; i<SL; i++) {
        A.push_back(S[i]);
        if (A.back() == W.back() && A.length() >= WL) {
            int AL = A.length();
            if (A.substr(AL-WL, WL) == W) {
                A.erase(AL-WL);
            }
        }
    }

    // Control : Output
    cout << ((A.empty()) ? "FRULA" : A) << endl;
}

// Helper Functions
/* None */

