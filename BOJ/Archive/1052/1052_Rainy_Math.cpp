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
    int ans = 0;
    int numBottles = getNumBottles(N);
    int offset = 1;
    while (numBottles > K) {
        while ((N & offset) == 0) {
            offset <<= 1;
        }
        ans += offset;
        N += offset;
        numBottles = getNumBottles(N);
    }

    // Control : Output
    cout << ans << endl;
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
