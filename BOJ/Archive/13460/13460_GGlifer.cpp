//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
char board[10][10];
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
struct Point { int y, x; };
struct Status { Point R, B; };
Point O;
#define SUCCESS  1
#define CONTINUE 0
#define FAIL    -1

// Set up : Functions Declaration
bool operator == (const Point &u, const Point &v);
pair<int,Status> move(Status C, int dir);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    Point SR{}, SB{}; // start R, start B
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string line; cin >> line;
        for (int j=0; j<M; j++) {
            board[i][j] = line.at(j);
            if (board[i][j] != '#') {
                if (board[i][j] == 'R') {
                    SR.y = i; SR.x = j;
                }
                if (board[i][j] == 'B') {
                    SB.y = i; SB.x = j;
                }
                if (board[i][j] == 'O') {
                    O.y = i; O.x = j;
                }
                board[i][j] = '.';
            }
        }
    }

    // Process
    queue<pair<int,Status>> que;
    que.push({-1,{SR, SB}});

    int cnt = 0;
    while (not(que.empty())) {
        int size = que.size();
        cnt++;
        if (cnt > 10) break;
        while (size--) {
            Status C = que.front().second;
            int pd = que.front().first;
            que.pop();

            for (int i=0; i<4; i++) {
                if (pd == i || 3-pd == i) continue;
                int code; Status A{};
                tie(code, A) = move(C, i);

                // Control : Output
                if (code == SUCCESS) {
                    cout << cnt << endl;
                    exit(0);
                }

                else if (code == CONTINUE) {
                    que.push({i, A});
                }
            }
        }
    }

    // Control : Output
    cout << -1 << endl;
}

// Helper Functions
bool operator == (const Point &u, const Point &v)
{
    return make_tuple(u.x, u.y) == make_tuple(v.x, v.y);
}

pair<int,Status> move(Status C, int dir)
{
    Point CR = C.R;
    Point CB = C.B;

    bool isRMoved, isBMoved;
    bool isRFallen = false, isBFallen = false;

    do {
        isRMoved = false;
        isBMoved = false;

        if (not(isRFallen)) {
            int nry = CR.y + dy[dir];
            int nrx = CR.x + dx[dir];
            Point NR{nry, nrx};
            if (board[nry][nrx] != '#') {
                if (NR == O || not(NR == CB)) {
                    isRMoved = true;
                    CR = NR;
                }
            }
        }
        if (not(isBFallen)) {
            int nby = CB.y + dy[dir];
            int nbx = CB.x + dx[dir];
            Point NB{nby, nbx};
            if (board[nby][nbx] != '#') {
                if (NB == O || not(NB == CR)) {
                    isBMoved = true;
                    CB = NB;
                }
            }
        }

        isRFallen = (CR == O);
        isBFallen = (CB == O);
    } while (isRMoved || isBMoved);

    if (isBFallen) {
        return {FAIL, {CR, CB}};
    } else if (isRFallen) {
        return {SUCCESS, {CR, CB}};
    } else {
        return {CONTINUE, {CR, CB}};
    }
}