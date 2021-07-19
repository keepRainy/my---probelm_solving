//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int A, B;
int N, M;
int T[100+1][100+1];
struct Robot { int no, x, y, dir; };
Robot R[100+1];
struct Command { int no; char type; int rep; };
Command C[100+1];
enum Direction { NORTH, WEST, EAST, SOUTH };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, -1, +1, 0};
enum Rotate { LEFT, RIGHT };
int D[4][2] = {
        {WEST, EAST},
        {SOUTH, NORTH},
        {NORTH, SOUTH},
        {EAST, WEST}
};
struct Result { bool status; int X, Y; };
#define NONE (-1)
#define WALL 0
#define ERROR false

// Set up : Functions Declaration
bool isValid(int y, int x);
Result exe(Command cmd);
Result typeL(Command cmd);
Result typeR(Command cmd);
Result typeF(Command cmd);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> A >> B;
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        int x, y; char d;
        cin >> x >> y >> d;
        int dir;
        switch (d) {
            case 'N': dir = 0; break;
            case 'W': dir = 1; break;
            case 'E': dir = 2; break;
            case 'S': dir = 3; break;
            default: throw runtime_error("Invalid Direction");
        }
        R[i] = {i, x, y, dir};
        T[y][x] = i;
    }
    for (int i=1; i<=M; i++) {
        int no; char type; int rep;
        cin >> no >> type >> rep;
        C[i] = {no, type, rep};
    }

    // Process
    bool isThereError = false;
    Result res{};
    for (int i=1; i<=M; i++) {
        res = exe(C[i]);
        if (res.status == ERROR) {
            isThereError = true;
            break;
        }
    }

    // Control : Output
    if (not(isThereError))
        cout << "OK" << endl;
    else {
        (res.Y == WALL) ?
        printf("Robot %d crashes into the wall\n", res.X) :
        printf("Robot %d crashes into robot %d\n", res.X, res.Y);
    }
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 1 && y <= B && x >= 1 && x <= A;
}

Result exe(Command cmd)
{
    char type = cmd.type;
    switch (type) {
        case 'L': return typeL(cmd);
        case 'R': return typeR(cmd);
        case 'F': return typeF(cmd);
        default: throw runtime_error("Invalid Type");
    }
}

Result typeL(Command cmd)
{
    Robot &r = R[cmd.no];
    for (int i=0; i<cmd.rep; i++) {
        r.dir = D[r.dir][LEFT];
    } return {true, NONE, NONE};
}

Result typeR(Command cmd)
{
    Robot &r = R[cmd.no];
    for (int i=0; i<cmd.rep; i++) {
        r.dir = D[r.dir][RIGHT];
    } return {true, NONE, NONE};
}

Result typeF(Command cmd)
{
    Robot &r = R[cmd.no];
    int cy = r.y, cx = r.x;
    for (int i=0; i<cmd.rep; i++) {
        int ny = cy + dy[r.dir];
        int nx = cx + dx[r.dir];
        if (not(isValid(ny, nx)))
            return {ERROR, r.no, WALL};
        if (T[ny][nx] != 0)
            return {ERROR, r.no, T[ny][nx]};
        cy = ny, cx = nx;
    }
    swap(T[r.y][r.x], T[cy][cx]);
    r.y = cy, r.x = cx;
    return {true, NONE, NONE};
}
