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
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int K, N;
    cin >> K >> N;
    int L[K];
    for (int i=0; i<K; i++) {
        cin >> L[i];
    }

    // Process
    long l = 1;
    long r = *max_element(L, L+K);

    long ans = -1;
    while (l <= r) {
        long m = (l + r) / 2;
        long cnt = 0;
        for (int len : L) {
            cnt += len / m;
        }

        if (cnt >= N) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

