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
    int T; cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i=0; i<M; i++) {
            int a, b;
            cin >> a >> b;
        }

        // Control : Output
        cout << N-1 << endl;
    }
}

// Helper Functions
/* None */

