//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Work { int t, s; };

// Set up : Functions Declaration
bool operator < (const Work &u, const Work &v);
bool isPossible(int h, vector<Work> &works);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    vector<Work> works(N);
    for (int i=0; i<N; i++) {
        cin >> works[i].t >> works[i].s;
    }

    // Process
    sort(works.begin(), works.end());

    int l = 0;
    Work fw = works.front();
    int r = fw.s - fw.t;

    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (isPossible(m, works)) {
            ans = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (const Work &u, const Work &v)
{
    return make_pair(u.s, u.t) < make_pair(v.s, v.t);
}

bool isPossible(int h, vector<Work> &works)
{
    for (Work work : works) {
        h += work.t;
        if (h > work.s)
            return false;
    } return true;
}
