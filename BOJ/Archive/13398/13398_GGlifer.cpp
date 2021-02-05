//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>
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
    int N; cin >> N;
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    int l2r[N], r2l[N];
    memset(l2r, 0, sizeof(l2r));
    memset(r2l, 0, sizeof(r2l));

    l2r[0] = A[0];
    for (int i=1; i<N; i++) {
        l2r[i] = A[i] + ((l2r[i-1] < 0) ? 0 : l2r[i-1]);
    }
    r2l[N-1] = A[N-1];
    for (int i=N-2; i>=0; i--) {
        r2l[i] = A[i] + ((r2l[i+1] < 0) ? 0 : r2l[i+1]);
    }

    int ans = max(*max_element(l2r, l2r+N), *max_element(r2l, r2l+N));
    if (N > 1) {
        for (int i=0; i<N; i++) {
            if (i == 0) {
                ans = max(ans, r2l[1]);
            } else if (i == N-1) {
                ans = max(ans, l2r[N-2]);
            } else {
                ans = max(ans, l2r[i-1]+r2l[i+1]);
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

