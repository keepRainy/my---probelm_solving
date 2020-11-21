//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <set>
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
    int A[N+1];
    for (int i=1; i<=N; i++)
        cin >> A[i];

    // Process
    bool isCycle[N+1];
    memset(isCycle, false, sizeof(isCycle));
    set<int> ans;
    for (int i=1; i<=N; i++) {
        if (isCycle[i]) continue;

        set<int> s;
        s.insert(i);
        int n = A[i];
        while (true) {
            if (n == i) {
                ans.insert(s.begin(), s.end());
                for (int e : s) { isCycle[e] = true; }
                break;
            }

            if (s.find(n) != s.end()) break;
            s.insert(n);
            n = A[n];
        }
    }

    // Control : Output
    cout << ans.size() << endl;
    for (int n : ans) {
        cout << n << endl;
    }
}

// Helper Functions
/* None */

