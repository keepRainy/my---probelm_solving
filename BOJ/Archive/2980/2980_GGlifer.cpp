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
    int N, L;
    cin >> N >> L;
    int D[N], R[N], G[N];
    for (int i=0; i<N; i++)
        cin >> D[i] >> R[i] >> G[i];

    // Process
    int time = 0, cd = 0;
    for (int i=0; i<N; i++) {
        int d = D[i], r = R[i], g = G[i];
        time += (d-cd);
        cd = d;
        int v = time % (r+g);
        if (v < r) {
            time += r-v;
        } else continue;
    } time += (L-cd);

    // Control : Output
    cout << time << endl;
}

// Helper Functions
/* None */

