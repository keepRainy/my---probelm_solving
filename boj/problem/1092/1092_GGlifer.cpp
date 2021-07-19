//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <deque>
#include <algorithm>

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
    deque<int> C(N);
    for (int i=0; i<N; i++)
        cin >> C[i];
    int M; cin >> M;
    deque<int> B(M);
    for (int i=0; i<M; i++)
        cin >> B[i];

    // Process
    sort(C.begin(), C.end());
    sort(B.begin(), B.end());

    // Control : Output
    if (C.back() < B.back()) {
        cout << -1 << endl;
        exit(0);
    }

    // Process
    int ans = 0;
    while (not(B.empty())) {
        ans++;
        int s = C.size();
        while (s--) {
            int c = C.front();
            C.pop_front();
            auto pos = upper_bound(B.begin(), B.end(), c);
            if (pos == B.begin()) continue;
            B.erase(prev(pos));
            C.push_back(c);
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

