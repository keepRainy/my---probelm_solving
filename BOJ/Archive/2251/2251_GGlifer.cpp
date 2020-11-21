//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <set>

using namespace std;

#define endl '\n'

// Set up : Global Variables
typedef vector<int> Status;

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int A, B, C;
    cin >> A >> B >> C;

    // Process
    Status v = {A, B, C};

    bool isVisited[A+1][B+1];
    memset(isVisited, false, sizeof(isVisited));

    queue<Status> que;
    que.push(vector<int>({0,0,C}));
    isVisited[0][0] = true;

    set<int> ans;
    while (not(que.empty())) {
        Status c = que.front(); que.pop();
        if (c[0] == 0) {
            ans.insert(c[2]);
        }

        for (int f=0; f<=2; f++) {
            for (int t=0; t<=2; t++) {
                if (f == t) continue;
                Status n = c;
                n[t] += n[f];
                n[f] = 0;
                if (n[t] > v[t]) {
                    n[f] += n[t]-v[t];
                    n[t] = v[t];
                }
                if (not(isVisited[n[0]][n[1]])) {
                    isVisited[n[0]][n[1]] = true;
                    que.push(n);
                }
            }
        }
    }

    // Control : Output
    for (int n : ans) {
        cout << n << ' ';
    }
}

// Helper Functions
/* None */

