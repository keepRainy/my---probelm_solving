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
struct Line { int s, e; };

// Set up : Functions Declaration
bool operator < (Line u, Line v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    vector<Line> L(N);
    for (int i=0; i<N; i++) {
        cin >> L[i].s >> L[i].e;
    }

    // Process
    sort(L.begin(), L.end());
    int cs = L[0].s, ce = L[0].e;
    int ans = 0;
    for (int i=1; i<N; i++) {
        int ls = L[i].s, le = L[i].e;
        if (ls > ce) {
            ans += ce-cs;
            cs = ls, ce = le;
        } else {
            ce = max(ce, le);
        }
    } ans += ce-cs;

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (Line u, Line v)
{
    return make_pair(u.s, u.e) < make_pair(v.s, v.e);
}
