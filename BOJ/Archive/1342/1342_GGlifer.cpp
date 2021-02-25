//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <functional>

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
    function<bool(string)> isFortune = [](string s) {
        string u = s;
        u.erase(unique(u.begin(), u.end()), u.end());
        return s == u;
    };

    sort(S.begin(), S.end());
    int ans = 0;
    do {
        if (isFortune(S)) ans++;
    } while (next_permutation(S.begin(), S.end()));

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

