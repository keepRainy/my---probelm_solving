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
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        int R[N];
        for (int i=0; i<N; i++) {
            cin >> R[i];
        }

        // Process
        bool isUsed[N+1];
        memset(isUsed, false, sizeof(isUsed));

        int S[N];
        bool isPossible = true;
        for (int i=N-1; i>=0; i--) {
            int s = R[i]+1;
            for (; s<=N; s++) {
                if (isUsed[s]) continue;
                int cnt = 0;
                for (int k=1; k<s; k++) {
                    if (not(isUsed[k])) { cnt++; }
                }

                if (cnt == R[i]) {
                    S[i] = s;
                    isUsed[s] = true;
                    break;
                }
            }

            if (s > N) {
                isPossible = false;
                break;
            }
        }

        // Control : Output
        if (not(isPossible)) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i=0; i<N; i++) {
                cout << S[i] << ' ';
            } cout << endl;
        }
    }
}

// Helper Functions
/* None */

