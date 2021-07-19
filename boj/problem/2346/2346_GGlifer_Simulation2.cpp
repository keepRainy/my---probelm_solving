//
//  BOJ
//  ver.C++
//
//  Created by Rainy
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
    int N; cin >> N;
    int W[N+1];
    for (int i=1; i<=N; i++) {
        cin >> W[i];
    }

    // Process
    bool isPopped[N+1];
    memset(isPopped, false, sizeof(isPopped));

    int ans[N+1];
    int idx = 1;
    for (int i=1; i<=N; i++) {
        ans[i] = idx;
        isPopped[idx] = true;
        if (i == N) break;

        if (W[idx] < 0) {
            int cnt = abs(W[idx]);
            while (cnt--) {
                idx--;
                while (not(idx >= 1 && idx <= N && not(isPopped[idx]))) {
                    idx--;
                    if (idx < 1) { idx = N-idx; }
                }
            }
        }
        else {
            int cnt = abs(W[idx]);
            while (cnt--) {
                idx++;
                while (not(idx >= 1 && idx <= N && not(isPopped[idx]))) {
                    idx++;
                    if (idx > N) { idx = idx-N; }
                }
            }
        }
    }

    // Control : Output
    for (int i=1; i<=N; i++) {
        cout << ans[i] << ' ';
    }
}

// Helper Functions
/* None */

