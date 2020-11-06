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
    sort(A, A+N);
    int s = 0, e = N-1;
    int val = A[s] + A[e], ans[2] = {A[s], A[e]};
    while (s < e) {
        int sum = A[s] + A[e];
        if (abs(val) > abs(sum)) {
            val = sum;
            ans[0] = A[s], ans[1] = A[e];
        } if (abs(val) == 0) break;

        (sum > 0) ? e-- : s++;
    }

    // Control : Output
    cout << ans[0] << ' ' << ans[1] << endl;
}

// Helper Functions
/* None */

