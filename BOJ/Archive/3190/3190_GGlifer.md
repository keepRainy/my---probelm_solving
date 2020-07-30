## \# Link

[https://www.acmicpc.net/problem/3190](https://www.acmicpc.net/problem/3190)

---

## \# Insight

- 뱀의 모습과 움직임을 시뮬레이션해야 한다  
  머리뿐만 아니라 __몸통과 꼬리__도 추적해야 한다
    
- 뱀을 자료구조로 구현할 수 있을까?
  머리가 앞이고 꼬리가 뒤라면 __Deque__ 으로 구현할 수 있지 않을까?

- 보드 위의 좌표들을 Deque 에 넣었다 뺐다 하면서 뱀의 모습과 움직임을 구현할 수 있을 것 같다!

---

## \# Point

- 문제는 좌표가 __(1,1)__ 부터 시작하지만 편의상 __(0,0)__ 부터 시작하는 것으로 가정하고 풀었다

- 게임은 뱀이 보드 밖으로 나가거나 자신의 몸에 부딪히면 끝난다 
  이때, __10초__까지 뱀이 움직이는 데 성공했고 __11초__에 뱀이 보드 밖으로 나가거나 자신의 몸에 부딪혔다면,
  이 게임은 __11초__에 끝나는 것으로 보아야 한다

- 시작 시간을 __n__초 증가시킨다고 하더라도 끝나는 시간이 똑같이 __n__초 증가하지 않는다
  위처럼 되려면, 모든 뱀의 방향 변환 정보의 __X__에 __n__을 더해주어야 한다

- 방향의 왼쪽과 오른쪽은 그 방향을 바라보고 있을 때를 기준으로 한다
  즉, __남쪽의 왼쪽은 서쪽이 아니라 동쪽이다__

---

#### \# Complexity - Time

- 뱀의 최대 생존시간은 max(X) + max(N) = 10100 정도이다

- 뱀의 모습과 움직임을 시뮬레이션 하는데 필요한 연산은 모두 O(1) 이다

- 시간 제한이 1초면 완 널널할 것 같다

#### \# Complexity - Memory

- 기본 = 1980KB (백준 1000번 문제 A+B 를 통과한 코드에서 사용한 메모리 양)

- ```int board[100][100]``` = 100 * 100 * 4B = 40KB

- ```deque<Point>``` = 100 * 100 * (4B + 4B) = 80KB

- 메모리 제한이 128MB면 완전 널널할 것 같다

---

## \# Warning

- 방향 변환 정보를 Queue 에 넣어서 시간이 될 때마다 꺼내 쓰는 방식으로 구현하였다
  때문에, 꺼내 쓸 때마다 Queue 가 비었는지 확인해야 한다

- (티스토리 행간 에러로 넣어줘야 되네 띠발!)

---

## \# Code - C++ / Comment

```C++
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
/* 보드 위의 3가지 상태 - 비어있음, 사과있음, 뱀있음 */
enum Status { EMPTY, APPLE, BODY };
int dy[4] = {+1, 0, 0, -1};
int dx[4] = {0, +1, -1, 0};
enum Direction { SOUTH, EAST, WEST, NORTH };
/* 방향 전환 정보 구조체 */
struct Info { int X; char C; };
/* 좌표 구조체 */
struct Point { int y, x; };
/* 뱀을 나타내는 구조체 - 방향, Deque */
struct Snake { int dir; deque<Point> body; };

// Set up : Functions Declaration
bool isValid(int y, int x); /* 보드 위에 있는 유효한 좌표면 true, 아니면 false */
bool move(Snake &snake); /* 뱀이 움직였다면 true, 움직이는데 실패했다면 false */
void updateDir(Snake &snake, queue<Info> &infos, int time); /* 뱀의 방향 전환 */


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
        // 문제는 (1,1) => 나는 (0,0)
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
    Snake snake{EAST, body}; // 뱀 초기화

    int time = 0;
    while (move(snake)) {
        time++;
        updateDir(snake, infos, time);
    } time++; // 실패하는데도 1초의 시간이 필요함

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
    Point head = snake.body.front(); // Deque 의 맨 앞 좌표는 뱀의 머리를 가리킴
    Point tail = snake.body.back();  // Deque 의 맨 뒤 좌표는 뱀의 꼬리를 가리킴

    int nhy = head.y + dy[dir]; // new head y
    int nhx = head.x + dx[dir]; // new head x

    // 새로운 뱀머리의 좌표가 유효하지 않은 좌표이거나 자기 몸통이면 움직이는데 실패
    if (not(isValid(nhy, nhx)) || board[nhy][nhx] == BODY) {
        return false;
    }

    // 새로운 뱀머리의 좌표에 사과가 없으면
    if (board[nhy][nhx] != APPLE) {
        // 꼬리를 줄여줌
        board[tail.y][tail.x] = EMPTY;
        snake.body.pop_back();
    }
    // 새로운 뱀머리의 좌표에 사과가 있든 없든 뱀머리는 늘려줌
    board[nhy][nhx] = BODY;
    snake.body.push_front({nhy, nhx});

    return true;
}

void updateDir(Snake &snake, queue<Info> &infos, int time)
{
    // Queue 가 비어있는지 확인
    if (infos.empty()) return;
    Info info = infos.front();
    if (info.X == time) {
        infos.pop();
        // 사실 아래부분을 2차원 전역 배열로 미리 선언해놓고 쓰면 더 좋다
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
```

---

## \# GitHub / No Comment

- [C++](https://github.com/GGlifer/Problem_solving/blob/master/BOJ/Archive/3190__%EB%B1%80/3190_GGlifer.cpp)
- Java / Not Yet
- Python 3 / Not Yet

> 지적, 조언, 첨언 모두 환영합니다!