//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Node { int no, dist; };
struct Status { int no, allDist, maxDist; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, s, e;
    cin >> N >> s >> e;
    vector<Node> L[N+1];
    for (int i=0; i<N-1; i++) {
        int no1, no2, dist;
        cin >> no1 >> no2 >> dist;
        L[no1].push_back({no2, dist});
        L[no2].push_back({no1, dist});
    }

    // Process
    queue<Status> que;
    bool isVisited[N+1];
    memset(isVisited, false, sizeof(isVisited));

    que.push({s, 0, 0});
    isVisited[s] = true;

    while (not(que.empty())) {
        int c = que.front().no;
        int ad = que.front().allDist;
        int md = que.front().maxDist;
        que.pop();

        // Control : Output
        if (c == e) {
            cout << ad - md << endl;
            exit(0);
        }

        for (Node node : L[c]) {
            int n = node.no;
            int d = node.dist;
            if (not(isVisited[n])) {
                isVisited[n] = true;
                que.push({n, ad+d, max(md,d)});
            }
        }
    }
}

// Helper Functions
/* None */

