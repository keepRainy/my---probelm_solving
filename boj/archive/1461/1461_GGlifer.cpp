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
    int N, M;
    cin >> N >> M;
    int P[N];
    for (int i=0; i<N; i++) {
        cin >> P[i];
    }

    // Process
    vector<int> pos, neg;
    for (int p : P) {
        (p > 0) ? pos.push_back(p) : neg.push_back(p);
    }
    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());

    int ans = 0;
    for (int i=0; i<pos.size(); i+=M) {
        ans += 2*pos[i];
    }
    for (int i=0; i<neg.size(); i+=M) {
        ans += 2*abs(neg[i]);
    }

    ans -= max(abs(*min_element(P, P+N)), *max_element(P, P+N));

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

