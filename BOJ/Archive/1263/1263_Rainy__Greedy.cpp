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
#define INF 987654321

// Set up : Functions Declaration
bool operator < (const Work &u, const Work &v);


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

    Work bw = works[N-1];
    int h = bw.s - bw.t;
    for (int i=N-2; i>=0; i--) {
        h = min(h, works[i].s);
        h -= works[i].t;
    }

    // Control : Output
    cout << ((h < 0) ? -1 : h) << endl;
}

// Helper Functions
bool operator < (const Work &u, const Work &v)
{
    return make_pair(u.s, u.t) < make_pair(v.s, v.t);
}
