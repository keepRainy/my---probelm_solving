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
    int K; cin >> K;
    int T[K];
    for (int i=0; i<K; i++)
        cin >> T[i];
    vector<int> AL[N+M+1];
    for (int i=1; i<=M; i++) {
        int num; cin >> num;
        AL[N+i].resize(num);
        for (int j=0; j<num; j++) {
            int no; cin >> no;
            AL[no].push_back(N+i);
            AL[N+i].push_back(no);
        }
    }

    // Process
    bool isVisited[N+M+1];
    memset(isVisited, false, sizeof(isVisited));

    queue<int> que;
    for (int t : T) {
        que.push(t);
        isVisited[t] = true;
    }

    while (not(que.empty())) {
        int c = que.front(); que.pop();
        for (int n : AL[c]) {
            if (not(isVisited[n])) {
                isVisited[n] = true;
                que.push(n);
            }
        }
    }

    int ans = 0;
    for (int i=N+1; i<=N+M; i++) {
        if (not(isVisited[i])) {
            ans++;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

