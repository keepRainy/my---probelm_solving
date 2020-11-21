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
int N;
int A[256];
int W[256][256];

// Set up : Functions Declaration
int f(int s, int e);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    for (int i=0; i<N; i++) {
        W[i][i] = i;
        for (int j=i+1; j<N; j++) {
            W[i][j] = (A[W[i][j-1]] > A[j]) ? j : W[i][j-1];
        }
    }

    int ans = f(0, N-1);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int f(int s, int e)
{
    if (s >= e) return 0;

    int val = 0;
    int i = W[s][e];
    if (i-1 >= s) {
        val += abs(A[i]-A[W[s][i-1]]);
        val += f(s,i-1);
    }
    if (i+1 <= e) {
        val += abs(A[i]-A[W[i+1][e]]);
        val += f(i+1,e);
    }

    return val;
}

