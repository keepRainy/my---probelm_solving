//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Pillar { int l, h; };

// Set up : Functions Declaration
bool operator < (Pillar u, Pillar v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    vector<Pillar> P(N);
    for (int i=0; i<N; i++)
        cin >> P[i].l >> P[i].h;

    // Process
    sort(P.begin(), P.end());

    stack<int> stl;
    for (int i=0; i<N; i++) {
        if (stl.empty() || P[stl.top()].h <= P[i].h) {
            stl.push(i);
        }
        // if (stl.empty() || P[stl.top()].h < P[i].h) {
        //     stl.push(i);
        // }
    }
    stack<int> str;
    for (int i=N-1; i>=0; i--) {
        if (str.empty() || P[str.top()].h < P[i].h) {
            str.push(i);
        }
        // if (str.empty() || P[str.top()].h <= P[i].h) {
        //     str.push(i);
        // }
    }

    int ans = P[stl.top()].h;
    while (stl.size() > 1) {
        int l1 = P[stl.top()].l; stl.pop();
        int l2 = P[stl.top()].l;
        int h = P[stl.top()].h;
        ans += (l1-l2)*h;
    }
    while (str.size() > 1) {
        int l1 = P[str.top()].l; str.pop();
        int l2 = P[str.top()].l;
        int h = P[str.top()].h;
        ans += (l2-l1)*h;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (Pillar u, Pillar v)
{
    return u.l < v.l;
}
