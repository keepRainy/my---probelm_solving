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
int clockNum(int n);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    string s;
    for (int i=0; i<4; i++) {
        char c; cin >> c;
        s += c;
    }

    // Process
    int cn = clockNum(stoi(s));

    int ans = 0;
    for (int i=1111; i<=cn; i++) {
        if (clockNum(i) == i) ans++;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int clockNum(int n)
{
    int ret = n;
    for (int i=0; i<3; i++) {
        n = n % 1000 * 10 + n / 1000;
        ret = min(ret, n);
    } return ret;
}
