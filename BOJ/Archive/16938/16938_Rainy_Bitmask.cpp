//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, L, R, X;
int A[15];

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> L >> R >> X;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    // Process
    int ans = 0;
    sort(A, A+N);
    for (int i=0; i<(1<<N); i++) {
        int bm = i;
        vector<int> diffs;
        for (int j=0; j<N; j++) {
            if (bm & (1<<j)) {
                diffs.push_back(A[j]);
            }
        }

        if (diffs.size() >= 2) {
            int easiest = diffs.front();
            int hardest = diffs.back();
            if (hardest - easiest >= X) {
                int sum = accumulate(diffs.begin(), diffs.end(), 0);
                if (sum >= L && sum <= R) {
                    ans++;
                }
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

