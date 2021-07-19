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
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, M;
    cin >> N >> M;
    vector<int> I[N+1], O[N+1];
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        I[a].push_back(b);
        O[b].push_back(a);
    }

    // Process
    bool isVisited[N+1];

    int ans = 0;
    for (int i=1; i<=N; i++) {

        memset(isVisited, false, sizeof(isVisited));
        int cnt_t = 0;
        queue<int> T;
        for (int t : I[i]) { T.push(t); isVisited[t] = true; }
        while (not(T.empty())) {
            int c = T.front();
            T.pop();
            cnt_t++;
            for (int n : I[c]) {
                if (not(isVisited[n])) {
                    isVisited[n] = true;
                    T.push(n);
                }
            }
        }

        memset(isVisited, false, sizeof(isVisited));
        int cnt_s = 0;
        queue<int> S;
        for (int s : O[i]) { S.push(s); isVisited[s] = true; }
        while (not(S.empty())) {
            int c = S.front();
            S.pop();
            cnt_s++;
            for (int n : O[c]) {
                if (not(isVisited[n])) {
                    isVisited[n] = true;
                    S.push(n);
                }
            }
        }

        if (cnt_s + cnt_t + 1 == N) {
            ans++;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

