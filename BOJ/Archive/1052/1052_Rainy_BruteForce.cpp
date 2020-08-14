//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
int getNumBottles(int v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, K;
    cin >> N >> K;

    // Process
    for (int i=0; i<=10e7; i++) {
        int v = N+i;
        int numBottles = getNumBottles(v);
        if (numBottles <= K) {
            // Control : Output
            cout << i << endl;
            exit(0);
        }
    }

    // Control : Output
    cout << -1 << endl;
}

// Helper Functions
int getNumBottles(int v)
{
    int cnt = 0;
    while (v) {
        if (v % 2) cnt++;
        v /= 2;
    } return cnt;
}
