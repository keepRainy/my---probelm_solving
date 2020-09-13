//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
bool isVisited[100][100];
enum Direction { UU, UR, DR, DD, DL, UL };
int dy[6] = {+2, +1, -1, -2, -1, +1};
int dx[6] = { 0, +2, +2,  0, -2, -2};
int D[6][2] = {
        {UL, UR}, /* UU */
        {UU, DR}, /* UR */
        {UR, DD}, /* DR */
        {DL, DR}, /* DD */
        {UL, DD}, /* DL */
        {UU, DL}  /* UL */
};

// Set up : Functions Declaration
int dfs(int cy, int cx, int cnt, int prevDir);

int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;

    // Process
    isVisited[48][50] = true;
    int ans = dfs(50, 50, 0, UU);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int dfs(int cy, int cx, int cnt, int prevDir)
{
    if (isVisited[cy][cx])
        return (cnt == N) ? 1 : 0;
    if (cnt >= N)
        return 0;

    isVisited[cy][cx] = true;

    int ret = 0;
    for (int nextDir : D[prevDir]) {
        int ny = cy + dy[nextDir];
        int nx = cx + dx[nextDir];
        ret += dfs(ny, nx, cnt+1, nextDir);
    }

    isVisited[cy][cx] = false;

    return ret;
}
