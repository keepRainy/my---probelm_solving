//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <deque>
#include <queue>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
int board[100][100];
enum Status { EMPTY, APPLE, BODY };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
enum Direction { SOUTH, EAST, WEST, NORTH };
struct Info { int X; char C; };
struct Point { int y, x; };
struct Snake { int dir; deque<Point> body; };

// Set up : Functions Declaration
bool isValid(int y, int x);
bool move(Snake &snake);
void updateDir(Snake &snake, queue<Info> &infos, int time);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int K;
    cin >> N >> K;
    for (int i=0; i<K; i++) {
        int r, c;
        cin >> r >> c;
        board[r-1][c-1] = APPLE;
    }
    int L; cin >> L;
    queue<Info> infos;
    for (int i=0; i<L; i++) {
        int X; char C;
        cin >> X >> C;
        infos.push({X, C});
    }

    // Process
    deque<Point> body;
    body.push_back({0, 0});
    Snake snake{EAST, body};

    int time = 0;
    while (move(snake)) {
        time++;
        updateDir(snake, infos, time);
    } time++;

    // Control : Output
    cout << time << endl;
}

// Helper Functions
bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < N;
}

bool move(Snake &snake)
{
    int dir = snake.dir;
    Point head = snake.body.front();
    Point tail = snake.body.back();

    int nhy = head.y + dy[dir]; /* new head y */
    int nhx = head.x + dx[dir]; /* new head x */

    if (not(isValid(nhy, nhx)) || board[nhy][nhx] == BODY) {
        return false;
    }

    if (board[nhy][nhx] == APPLE) {
        board[nhy][nhx] = BODY;
        snake.body.push_front({nhy, nhx});
    } else {
        board[nhy][nhx] = BODY;
        snake.body.push_front({nhy, nhx});
        board[tail.y][tail.x] = EMPTY;
        snake.body.pop_back();
    }

    return true;
}

void updateDir(Snake &snake, queue<Info> &infos, int time)
{
    if (infos.empty()) return;
    Info info = infos.front();
    if (info.X == time) {
        infos.pop();
        if (info.C == 'L') {
            switch (snake.dir) {
                case SOUTH: snake.dir = EAST;  return;
                case EAST:  snake.dir = NORTH; return;
                case WEST:  snake.dir = SOUTH; return;
                case NORTH: snake.dir = WEST;  return;
                default: throw;
            }
        }
        if (info.C == 'D') {
            switch (snake.dir) {
                case SOUTH: snake.dir = WEST;  return;
                case EAST:  snake.dir = SOUTH; return;
                case WEST:  snake.dir = NORTH; return;
                case NORTH: snake.dir = EAST;  return;
                default: throw;
            }
        }
    }
}
