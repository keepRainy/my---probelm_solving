//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <map>

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
    string NO = "NO";
    string INIT = "INIT";
    map<string,vector<string>> next;
    next["START"] = {"0", "1"};
    next["1"] = {"10", NO};
    next["10"] = {"100", NO};
    next["100"] = {"100~", "100~1"};
    next["100~"] = {"100~", "100~1"};
    next["100~1"] = {"0", "100~1~"};
    next["100~1~"] = {"10 or 0", "100~1~"};
    next["0"] = {NO, "01"};
    next["01"] = {"0", "1"};
    next["10 or 0"] = {"100", "01"};

    string state = INIT;
    for (char c : sound) {
        int v = c - '0';
        state = next[state][v];
        if (state == NO) break;
    }

    // Control : Output
    if (state == "100~1" || state == "100~1~" || state == "01")
        cout << "SUBMARINE" << endl;
    else
        cout << "NOISE" << endl;
}

// Helper Functions
/* None */

