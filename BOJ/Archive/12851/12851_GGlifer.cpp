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
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, K;
    cin >> N >> K;

    // Control : Output
    if (N >= K) {
        cout << N-K << endl;
        cout << 1 << endl;
        exit(0);
    }

    // Process
    bool isVisited[2*K];
    memset(isVisited, false, sizeof(isVisited));

    queue<int> que;
    que.push(N);

    int minTime = -1, numMethods = 0;
    int time = -1;
    while (not(que.empty())) {
        time++;
        int size = que.size();
        while (size--) {
            int cp = que.front(); que.pop();

            isVisited[cp] = true;

            if (cp == K) {
                if (minTime == -1) {
                    minTime = time;
                } numMethods++;
                continue;
            }

            int D[3] = {-1, +1, cp};
            for (int dp : D) {
                int np = cp + dp;
                if (np >= 0 && np < 2*K && not(isVisited[np])) {
                    que.push(np);
                }
            }
        }
        if (minTime != -1) break;
    }

    // Control : Output
    cout << minTime << endl;
    cout << numMethods << endl;
}

// Helper Functions
/* None */

