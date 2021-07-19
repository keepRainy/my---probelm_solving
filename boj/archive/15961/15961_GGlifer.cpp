//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>

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
    int N, d, k, c;
    cin >> N >> d >> k >> c;
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    int C[d+1];
    memset(C, 0, sizeof(C));

    int ans = 0, cnt = 0;
    for (int i=0; i<k; i++) {
        C[A[i]]++;
        if (C[A[i]] == 1) cnt++;
    } if (C[c] == 0) {
        C[c]++;
        if (C[c] == 1) cnt++;
    } ans = cnt;

    for (int i=1; i<=N-1; i++) {
        if (C[A[i-1]] > 0) {
            C[A[i-1]]--;
            if (C[A[i-1]] == 0) {
                cnt--;
            }
        }

        C[A[(i+k-1)%N]]++;
        if (C[A[(i+k-1)%N]] == 1) {
            cnt++;
        }

        if (C[c] == 0) {
            C[c]++;
            cnt++;
        }

        ans = max(ans, cnt);
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

