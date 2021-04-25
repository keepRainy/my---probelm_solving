//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <algorithm>
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
    int A[N][9];
    for (int i=0; i<N; i++)
        for (int j=0; j<9; j++)
            cin >> A[i][j];

    // Process
    vector<int> O = {1, 2, 3, 4, 5, 6, 7, 8};

    int ans = -1;
    do {
        int tmp = 0;
        int idx = 0;
        for (int i=0; i<N; i++) {
            int out = 0;
            bool base[3+1];
            memset(base, false, sizeof(base));
            vector<int> R(8);
            for (int j=0; j<8; j++) {
                R[j] = A[i][O[j]];
            } R.insert(R.begin()+3, A[i][0]);

            while (out < 3) {
                int r = R[idx];
                idx = (idx+1) % 9;
                if (r == 0) {
                    out++;
                } else {
                    for (int j=3; j>=1; j--) {
                        if (base[j]) {
                            if (j+r >= 4)
                                tmp++;
                            else
                                base[j+r] = true;
                            base[j] = false;
                        }
                    }
                    if (r >= 4)
                        tmp++;
                    else
                        base[r] = true;
                }
            }
        }
        ans = max(ans, tmp);
    } while (next_permutation(O.begin(), O.end()));

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */
