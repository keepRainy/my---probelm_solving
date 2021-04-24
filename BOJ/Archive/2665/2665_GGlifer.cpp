//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <deque>
#include <cstring>
#include <functional>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point { int y, x; };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    char A[N][N];
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> A[i][j];

    // Process
    function<bool(int,int)> isValid = [N](int y, int x){
        return y >= 0 && y < N && x >= 0 && x < N;
    };

    int dp[N][N];
    memset(dp, -1, sizeof(dp));
    deque<Point> deq;

    dp[0][0] = 0;
    deq.push_back({0, 0});

    int ans = -1;
    while (not(deq.empty())) {
        auto [cy, cx] = deq.front();
        deq.pop_front();

        if (cy == N-1 && cx == N-1) {
            ans = dp[cy][cx];
            break;
        }

        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (isValid(ny, nx)) {
                if (A[ny][nx] == '1' && (dp[ny][nx] == -1 || dp[ny][nx] > dp[cy][cx])) {
                    dp[ny][nx] = dp[cy][cx];
                    deq.push_front({ny, nx});
                }
                if (A[ny][nx] == '0' && (dp[ny][nx] == -1 || dp[ny][nx] > dp[cy][cx] + 1)) {
                    dp[ny][nx] = dp[cy][cx] + 1;
                    deq.push_back({ny, nx});
                }
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */
