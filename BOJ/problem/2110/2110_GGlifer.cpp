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
    int N, C;
    cin >> N >> C;
    long X[N];
    for (int i=0; i<N; i++) {
        cin >> X[i];
    }

    // Process
    sort(X, X+N);

    long l = 1;
    long r = X[N-1];

    long ans = -1;
    while (l <= r) {
        long m = (l + r) / 2;

        int cnt = 1;
        long cpos = X[0];
        for (int i=1; i<N; i++) {
            if (cpos+m <= X[i]) {
                cnt++;
                cpos = X[i];
            }
        }

        if (cnt >= C) {
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

