//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
int space[20][20];
struct Point { int y, x; };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
struct BabyShark { Point pos; int size; int feed; } babyShark;
struct Fish { int dist; Point pos; };

// Set up : Functions Declaration
bool operator < (const Fish &u, const Fish &v);
bool isValid(int y, int x);
Fish bfs(Point s);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> space[i][j];
            if (space[i][j] == 9) {
                babyShark.pos = {i, j};
                space[i][j] = 0;
            }
        }
    }

    // Process
    babyShark.size = 2;
    babyShark.feed = 0;
    int time = 0;
    while (true) {
        Fish target = bfs(babyShark.pos);
        if (target.dist == -1) break;

        time += target.dist;
        babyShark.pos = target.pos;
        space[target.pos.y][target.pos.x] = 0;
        babyShark.feed++;
        if (babyShark.feed == babyShark.size) {
            babyShark.size++;
            babyShark.feed = 0;
        }
    }

    // Control : Output
    cout << time << endl;
}

// Helper Functions
bool operator < (const Fish &u, const Fish &v)
{
    if (u.dist != v.dist) return u.dist < v.dist;
    if (u.pos.y != v.pos.y) return u.pos.y < v.pos.y;
    return u.pos.x < v.pos.x;
}

bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < N;
}

Fish bfs(Point s)
{
    queue<Point> que;
    bool isVisited[N][N];
    memset(isVisited, false, sizeof(isVisited));
    vector<Fish> fishes;

    que.push(s);
    isVisited[s.y][s.x] = true;

    int dist = -1;
    while (not(que.empty())) {
        int size = que.size();
        dist++;
        while (size--) {
            Point c = que.front(); que.pop();
            if (space[c.y][c.x] != 0 && space[c.y][c.x] < babyShark.size) {
                fishes.push_back({dist, c});
            }

            for (int i=0; i<4; i++) {
                int ny = c.y + dy[i];
                int nx = c.x + dx[i];
                if (isValid(ny, nx) && not(isVisited[ny][nx]) && space[ny][nx] <= babyShark.size) {
                    isVisited[ny][nx] = true;
                    que.push({ny, nx});
                }
            }
        }
    }

    if (fishes.empty())
        return {-1, {-1, -1}};
    else {
        sort(fishes.begin(), fishes.end());
        return fishes.front();
    }
}
