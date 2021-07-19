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
    int N, M, L;
    cin >> N >> M >> L;
    int A[N+2];
    for (int i=1; i<=N; i++)
        cin >> A[i];

    // Process
    A[0] = 0, A[N+1] = L;
    sort(A, A+(N+2));
    int l = 1, r = A[0];
    for (int i=1; i<N; i++) {
        r = max(r, A[i]-A[i-1]);
    } r = max(r, L-A[N-1]);

    int ans = -1;
    while (l <= r) {
        int m = (l+r)/2;
        int cnt = 0;
        for (int i=1; i<N+2; i++) {
            cnt += (A[i]-A[i-1]-1)/m;
        }

        if (cnt > M) {
            l = m+1;
        } else {
            ans = m;
            r = m-1;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

