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
bool comp(long u, long v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    long A[N];
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    // Process
    sort(A, A+N, comp);

    // Control : Output
    for (int i=0; i<N; i++) {
        cout << A[i] << ' ';
    }
}

// Helper Functions
bool comp(long u, long v)
{
    int u2 = 0, u3 = 0;
    while (u%2 == 0) {
        u2++;
        u /= 2;
    }
    while (u%3 == 0) {
        u3++;
        u /= 3;
    }

    int v2 = 0, v3 = 0;
    while (v%2 == 0) {
        v2++;
        v /= 2;
    }
    while (v%3 == 0) {
        v3++;
        v /= 3;
    }

    return make_pair(u3, -u2) > make_pair(v3, -v2);
}
