//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

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
    int N, K;
    cin >> N >> K;
    double A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    sort(A, A+N);
    double tm = accumulate(A+K, A+N-K, (double)0) / (N-2*K);
    fill(A, A+K, A[K]);
    fill(A+N-K, A+N, A[N-K-1]);
    double am = accumulate(A, A+N, (double)0) / N;

    // Control : Output
    printf("%.2f\n", round(tm*100)/100);
    printf("%.2f\n", round(am*100)/100);
}

// Helper Functions
/* None */
