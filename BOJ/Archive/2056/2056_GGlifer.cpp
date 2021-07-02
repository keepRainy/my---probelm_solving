//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Operation { int no, t; };

// Set up : Functions Declaration
bool operator < (const Operation &u, const Operation &v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int T[N+1]; vector<int> K[N+1]; int C[N+1];
    for (int i=1; i<=N; i++) {
        cin >> T[i];
        int n; cin >> n;
        C[i] = n;
        for (int j=0; j<n; j++) {
            int no; cin >> no;
            K[no].push_back(i);
        }
    }

    // Process
    priority_queue<Operation> pq;
    for (int i=1; i<=N; i++) {
        if (C[i] == 0) {
            pq.push({i, T[i]});
        }
    }

    int ans = -1;
    while (not(pq.empty())) {
        auto [c, t] = pq.top();
        pq.pop();

        for (int n : K[c]) {
            C[n]--;
            if (C[n] == 0) {
                pq.push({n, t+T[n]});
            }
        }

        if (pq.empty()) {
            ans = t;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (const Operation &u, const Operation &v)
{
    return make_pair(u.t, u.no) > make_pair(v.t, v.no);
}
