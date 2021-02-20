//
//  Codeforces
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
int DP(vector<int> A);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    while (true) {
        int M, N;
        cin >> M >> N;
        if (M == 0 && N == 0) break;

        vector<int> B[M];
        for (int i=0; i<M; i++) {
            B[i].resize(N);
            for (int j=0; j<N; j++) {
                cin >> B[i][j];
            }
        }

        // Process
        vector<int> R(M);
        for (int i=0; i<M; i++) {
            R[i] = DP(B[i]);
        } int ans = DP(R);

        // Control : Output
        cout << ans << endl;
    }
}

// Helper Functions
int DP(vector<int> A)
{
    int L = A.size();
    if (L == 1) return A[0];

    int dp[L];
    memset(dp, 0, sizeof(dp));
    dp[0] = A[0];
    dp[1] = max(A[0], A[1]);
    for (int i=2; i<L; i++) {
        dp[i] = max(dp[i-1], A[i]+dp[i-2]);
    }

    return dp[L-1];
}
