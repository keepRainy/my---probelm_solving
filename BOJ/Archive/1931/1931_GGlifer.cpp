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
struct Meeting { int s, e; };

// Set up : Functions Declaration
bool operator < (Meeting u, Meeting v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    vector<Meeting> M(N);
    for (int i=0; i<N; i++)
        cin >> M[i].s >> M[i].e;

    // Process
    sort(M.begin(), M.end());
    int ans = 0, et = -1;
    for (int i=0; i<N; i++) {
        if (et <= M[i].s) {
            ans++;
            et = M[i].e;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (Meeting u, Meeting v)
{
    return make_pair(u.e, u.s) < make_pair(v.e, v.s);
}
