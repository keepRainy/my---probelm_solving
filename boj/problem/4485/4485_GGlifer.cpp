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
#include <functional>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point { int y, x; };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
struct State { int c; Point p; };

// Set up : Functions Declaration
bool operator < (State u, State v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int tc = 0;
    while (true) {
        int N; cin >> N;
        if (N == 0) break;

        tc++;
        int A[N][N];
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                cin >> A[i][j];

        // Process
        function<bool(int,int)> isValid = [N](int y, int x){
            return y >= 0 && y < N && x >= 0 && x < N;
        };

        bool isDone[N][N];
        memset(isDone, false, sizeof(isDone));
        int dp[N][N];
        memset(dp, -1, sizeof(dp));
        priority_queue<State> pq;

        dp[0][0] = A[0][0];
        pq.push({A[0][0], {0, 0}});

        while (not(pq.empty())) {
            int cc = pq.top().c;
            auto [cy, cx] = pq.top().p;
            pq.pop();

            if (dp[cy][cx] < cc) continue;

            isDone[cy][cx] = true;
            if (cy == N-1 && cx == N-1) break;

            for (int i=0; i<4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (isValid(ny, nx) && not(isDone[ny][nx])) {
                    if (dp[ny][nx] == -1 || dp[ny][nx] > dp[cy][cx] + A[ny][nx]) {
                        dp[ny][nx] = dp[cy][cx] + A[ny][nx];
                        pq.push({dp[ny][nx], {ny, nx}});
                    }
                }
            }
        }

        // Control : Output
        printf("Problem %d: %d\n", tc, dp[N-1][N-1]);
    }
}

// Helper Functions
bool operator < (State u, State v)
{
    return u.c > v.c;
}
