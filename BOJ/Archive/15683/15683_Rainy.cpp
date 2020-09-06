//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
int office[8][8];
struct CCTV { int y, x, no; };
vector<CCTV> cctvs;
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
enum Direction { D, R, L, U };
vector<vector<int>> dir[5+1];
#define INF 987654321

// Set up : Functions Declaration
int f(int idx);
bool isValid(int y, int x);
void setUp(int y, int x, int d);
void allSet(int y, int x, const vector<int>& dirs);
void rollBack(int y, int x, int d);
void allBack(int y, int x, const vector<int>& dirs);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Process
    dir[1] = { {R}, {D}, {L}, {U} };
    dir[2] = { {L,R}, {D,U} };
    dir[3] = { {U,R}, {R,D}, {D,L}, {L,U} };
    dir[4] = { {L,U,R}, {U,R,D}, {R,D,L}, {D,L,U} };
    dir[5] = { {L,U,R,D} };

    // Set up : Input
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> office[i][j];
            if (office[i][j] > 0 && office[i][j] < 6) {
                cctvs.push_back({i, j, office[i][j]});
            }
        }
    }

    // Process
    int ans = f(0);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int f(int idx)
{
    if (idx == cctvs.size()) {
        int blind = 0;
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                if (office[i][j] == 0) {
                    blind++;
                }
            }
        }
        return blind;
    }

    int ret = INF;

    CCTV cctv = cctvs[idx];
    for (const vector<int>& dirs : dir[cctv.no]) {
        allSet(cctv.y, cctv.x, dirs);
        ret = min(ret, f(idx+1));
        allBack(cctv.y, cctv.x, dirs);
    }

    return ret;
}

bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < M;
}

void setUp(int y, int x, int d)
{
    int ny = y + dy[d];
    int nx = x + dx[d];
    while (isValid(ny, nx) && office[ny][nx] != 6) {
        if (office[ny][nx] <= 0) {
            office[ny][nx]--;
        }
        ny += dy[d];
        nx += dx[d];
    }
}

void allSet(int y, int x, const vector<int>& dirs)
{
    for (int d : dirs) {
        setUp(y, x, d);
    }
}

void rollBack(int y, int x, int d)
{
    int ny = y + dy[d];
    int nx = x + dx[d];
    while (isValid(ny, nx) && office[ny][nx] != 6) {
        if (office[ny][nx] < 0) {
            office[ny][nx]++;
        }
        ny += dy[d];
        nx += dx[d];
    }
}

void allBack(int y, int x, const vector<int>& dirs)
{
    for (int d : dirs) {
        rollBack(y, x, d);
    }
}
