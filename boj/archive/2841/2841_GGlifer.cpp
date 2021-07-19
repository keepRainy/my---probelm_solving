//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <stack>

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
    int N, P;
    cin >> N >> P;

    // Process
    stack<int> st[6+1];
    int ans = 0;
    for (int i=0; i<N; i++) {
        int l, p;
        cin >> l >> p;

        while (not(st[l].empty()) && st[l].top() > p) {
            st[l].pop();
            ans++;
        }

        if (st[l].empty() || st[l].top() < p) {
            st[l].push(p);
            ans++;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

