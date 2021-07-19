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
    bool S[N+1];
    for (int i=1; i<=N; i++)
        cin >> S[i];

    // Process
    int M; cin >> M;
    for (int i=0; i<M; i++) {
        int type, n;
        cin >> type >> n;

        if (type == 1) {
            for (int j=n; j<=N; j+=n) {
                S[j] ^= true;
            }
        }
        if (type == 2) {
            int j = 0;
            while (n-j >= 1 && n+j <= N && S[n-j] == S[n+j]) {
                S[n-j] = S[n+j] ^= true;
                j++;
            }
        }
    }

    // Control : Output
    for (int i=1; i<=N; i++) {
        cout << ((S[i]) ? 1 : 0);
        cout << ((i%20) ? ' ' : endl);
    }
}

// Helper Functions
/* None */

