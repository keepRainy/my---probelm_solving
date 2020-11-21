//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <vector>

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
    int N, H;
    cin >> N >> H;
    vector<int> U(N/2), D(N/2);
    for (int i=0; i<N/2; i++)
        cin >> U[i] >> D[i];

    // Process
    sort(U.begin(), U.end());
    sort(D.begin(), D.end());

    int ans1 = -1, ans2 = 0;
    for (int h=1; h<=H; h++) {
        int u_cnt = U.end() - lower_bound(U.begin(), U.end(), h);
        int d_cnt = D.end() - lower_bound(D.begin(), D.end(), H-h+1);
        int cnt = u_cnt + d_cnt;
        if (ans1 == -1 || ans1 > cnt) {
            ans1 = cnt;
            ans2 = 1;
        } else if (ans1 == cnt) {
            ans2++;
        }
    }

    // Control : Output
    cout << ans1 << ' ' << ans2 << endl;
}

// Helper Functions
/* None */

