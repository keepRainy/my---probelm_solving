//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Course { int s, t; };

// Set up : Functions Declaration
bool operator < (Course u, Course v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    vector<Course> C(N);
    for (int i=0; i<N; i++)
        cin >> C[i].s >> C[i].t;

    // Process
    sort(C.begin(), C.end());
    priority_queue<int,vector<int>,greater<>> R;
    R.push(0);
    for (int i=0; i<N; i++) {
        int s = C[i].s;
        int t = C[i].t;
        if (R.top() <= s) { R.pop(); }
        R.push(t);
    }

    // Control : Output
    cout << R.size() << endl;
}

// Helper Functions
bool operator < (Course u, Course v)
{
    return make_pair(u.s, u.t) < make_pair(v.s, v.t);
}
