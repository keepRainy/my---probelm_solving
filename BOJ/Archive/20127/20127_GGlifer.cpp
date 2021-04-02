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
    int up_cnt = 0, up_k = 0;
    int down_cnt = 0, down_k = 0;
    for (int i=1; i<N; i++) {
        if (A[i-1] > A[i]) {
            down_cnt++;
            down_k = i;
        }
        if (A[i-1] < A[i]) {
            up_cnt++;
            up_k = i;
        }
    }

    if (up_cnt > 1 || (up_cnt == 1 && not(A[N-1] >= A[0]))) {
        up_k = -1;
    }

    if (down_cnt > 1 || (down_cnt == 1 && not(A[N-1] <= A[0]))) {
        down_k = -1;
    }

    int ans;
    if (up_k != -1 && down_k != -1)
        ans = min(up_k, down_k);
    else if (up_k != -1)
        ans = up_k;
    else if (down_k != -1)
        ans = down_k;
    else
        ans = -1;

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

