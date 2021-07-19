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
bool isPalindrome(string s);
bool isPseudoPalindrome(string s);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        string str; cin >> str;

        // Process
        // Control : Output
        cout << (isPalindrome(str) ? 0 : isPseudoPalindrome(str) ? 1 : 2) << endl;
    }
}

// Helper Functions
bool isPalindrome(string s)
{
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
}

bool isPseudoPalindrome(string s)
{
    int N = s.length();
    for (int i=0; i<N/2; i++) {
        if (s[i] != s[N-1-i]) {
            string s1 = s.substr(i+1, N-1-2*i);
            string s2 = s.substr(i, N-1-2*i);
            return isPalindrome(s1) || isPalindrome(s2);
        }
    }
    return false;
}
