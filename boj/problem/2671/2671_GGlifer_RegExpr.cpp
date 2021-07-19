//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <regex>

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
    string sound; cin >> sound;

    // Process
    regex re("(100+1+|01)+");
    bool isSubmarine = regex_match(sound, re);

    // Control : Output
    cout << ((isSubmarine) ? "SUBMARINE" : "NOISE") << endl;
}

// Helper Functions
/* None */

