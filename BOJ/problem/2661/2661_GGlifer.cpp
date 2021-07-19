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
int N;
string A;

// Set up : Functions Declaration
bool isGood(const string& s);
bool f(string s);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;

    // Process
    bool isPossible = f("");

    // Control : Output
    cout << ((isPossible) ? A : "-1") << endl;
}

// Helper Functions
bool isGood(const string& s)
{
    int len = s.length();
    for (int i=1; i<=len/2; i++) {
        string a1 = s.substr(len-2*i, i);
        string a2 = s.substr(len-i, i);
        if (a1 == a2) return false;
    } return true;
}

bool f(string s)
{
    if (s.length() == N) {
        A = s;
        return true;
    }
    else {
        for (char c : {'1', '2', '3'}) {
            if (isGood(s+c) && f(s+c)) {
                return true;
            }
        }
    }

    return false;
}
