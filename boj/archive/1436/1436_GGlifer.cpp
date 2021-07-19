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
bool is666(int n);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;

    // Process
    int n = 0, cnt = 0;
    while (cnt < N) {
        n++;
        if (is666(n)) cnt++;
    }

    // Control : Output
    cout << n << endl;
}

// Helper Functions
bool is666(int n)
{
    int cnt = 0;
    while (n) {
        if (n % 10 == 6) {
            cnt++;
            if (cnt == 3) {
                return true;
            }
        } else {
            cnt = 0;
        } n /= 10;
    } return false;
}
