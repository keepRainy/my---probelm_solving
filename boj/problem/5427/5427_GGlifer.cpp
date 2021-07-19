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
struct Point { int y, x; };
int dy[4] = {-1, 0, 0, +1};
int dx[4] = {0, +1, -1, 0};

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int W, H;
        cin >> W >> H;
        char B[H][W];
        int sy = -1, sx = -1;
        queue<Point> F;
        bool isVisited[H][W];
        memset(isVisited, false, sizeof(isVisited));
        for (int i=0; i<H; i++) {
            for (int j=0; j<W; j++) {
                cin >> B[i][j];
                if (B[i][j] == '@') {
                    sy = i, sx = j;
                    B[i][j] = '.';
                    isVisited[i][j] = true;
                } else if (B[i][j] == '*') {
                    F.push({i, j});
                }
            }
        }

        // Process
        int time = -1;
        queue<Point> Q;
        Q.push({sy, sx});

        int ans = -1;
        while (not(Q.empty()) && ans == -1) {
            time++;

            auto sz = F.size();
            while (sz--) {
                auto [cy, cx] = F.front();
                F.pop();

                for (int i=0; i<4; i++) {
                    int ay = cy + dy[i];
                    int ax = cx + dx[i];
                    if (ay >= 0 && ay < H && ax >= 0 && ax < W) {
                        if (B[ay][ax] == '.') {
                            B[ay][ax] = '*';
                            F.push({ay, ax});
                        }
                    }
                }
            }

            sz = Q.size();
            while (sz--) {
                auto [cy, cx] = Q.front();
                Q.pop();

                if (cy == 0 || cy == H-1 || cx == 0 || cx == W-1) {
                    ans = time+1;
                    break;
                }

                for (int i=0; i<4; i++) {
                    int ay = cy + dy[i];
                    int ax = cx + dx[i];
                    if (ay >= 0 && ay < H && ax >= 0 && ax < W) {
                        if (B[ay][ax] == '.' && not(isVisited[ay][ax])) {
                            isVisited[ay][ax] = true;
                            Q.push({ay ,ax});
                        }
                    }
                }
            }
        }

        // Control : Output
        if (ans == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }
}

// Helper Functions
/* None */

