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
    int N, M;
    cin >> N >> M;
    int K[M];
    for (int i=0; i<M; i++)
        cin >> K[i];

    // Process
    int ans = -1;
    long l = 1, r = *max_element(K, K+M);
    while (l <= r) {
        long m = (l+r)/2;
        long cnt = 0;
        for (int k : K) {
            cnt += (k+m-1)/m;
        }

        if (cnt <= N) {
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

