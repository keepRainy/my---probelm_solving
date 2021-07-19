//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <numeric>

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
    int M; cin >> M;
    int A[M];
    for (int i=0; i<M; i++)
        cin >> A[i];
    int K; cin >> K;

    // Process
    long double ans = 0;
    int N = accumulate(A, A+M, 0);
    for (int i=0; i<M; i++) {
        if (A[i] >= K) {
            long double prob = 1;
            for (int j=0; j<K; j++) {
                prob *= (A[i]-j);
                prob /= (N-j);
            } ans += prob;
        }
    }

    // Control : Output
    printf("%.9Lf\n", ans);
}

// Helper Functions
/* None */
