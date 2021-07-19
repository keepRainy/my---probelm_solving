//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Camp { int x, y, r; };

// Set up : Functions Declaration
bool isConnected(Camp u, Camp v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        Camp camps[N];
        for (int i=0; i<N; i++) {
            cin >> camps[i].x >> camps[i].y >> camps[i].r;
        }

        // Process
        vector<int> adjList[N];
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (isConnected(camps[i], camps[j])) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        bool isVisited[N];
        memset(isVisited, false, sizeof(isVisited));
        int ans = 0;
        for (int i=0; i<N; i++) {
            if (not(isVisited[i])) {
                ans++;

                queue<int> que;
                que.push(i);
                isVisited[i] = true;

                while (not(que.empty())) {
                    int c = que.front(); que.pop();
                    for (int n : adjList[c]) {
                        if (not(isVisited[n])) {
                            isVisited[n] = true;
                            que.push(n);
                        }
                    }
                }
            }
        }

        // Control : Output
        cout << ans << endl;
    }
}

// Helper Functions
bool isConnected(Camp u, Camp v)
{
    int dx = u.x - v.x;
    int dy = u.y - v.y;
    return dx*dx + dy*dy <= (u.r+v.r)*(u.r+v.r);
}
