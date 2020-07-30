## \# Link

[https://www.acmicpc.net/problem/13460](https://www.acmicpc.net/problem/13460)


---

## \# Insight

-   구슬이 움직이는 것을 시뮬레이션해야 한다  
    문제는 각각의 구슬이 벽 또는 다른 구슬에 닿거나 구멍에 떨어질 때까지 계속 움직여야 한다는 것이다  
    그렇게 보드를 한 번 기울일 때, 위와 같은 방식을 두 구슬이 움직이지 않을 때까지 반복해야 한다  
    중간에 구멍에 떨어지면 움직이지 않는 걸로 보아야 할 듯싶다
    
-   10번 이하로 빨간 구슬을 통해 빼낼 수 없으면 -1 을 출력한다는 건  
    11번 이상 기울이는 경우는 문제를 푸는 데 고려하지 않아도 된다는 뜻이다  
    그렇다면 전체 가능한 경우의 수는 **4^10번**으로 생각할 수 있다  
    시간제한이 2초인데 모든 경우가 **1024 \* 1024**번 정도면 다 해봐도 괜찮을 것 같다
    
-   그런데 생각해보면 **방금 전 기울인 쪽으로 보드를 기울이면 아무 의미가 없다**  
    구슬의 위치는 변하지 않을 것이기 때문이다  
    (예를 들면, 오른쪽으로 기울였다 다시 오른쪽으로 기울이는 것)  
    또한 **방금 전 기울였던 쪽과 반대로 구슬을 기울여도 아무 의미가 없다**  
    이전 구슬의 궤적에 구멍이 있었다면 어떻게든 게임은 끝났을 테고,  
    그렇지 않다면 기울이기 전의 구슬 위치로 되돌아갈 것이기 때문이다  
    (예를 들면, 왼쪽으로 기울였다 오른쪽으로 기울이는 것)  
    위와 같은 사실을 바탕으로 **2^10번**으로 경우의 수를 줄일 수 있을 것 같다
    
-   중간의 각 상태들은 빨간 구슬과 파란 구슬의 위치만 추적하면 될 것 같다  
    장애물과 구멍은 기울여도 변하지 않기 때문에 전역 변수로 공유해주면 좋을 것 같다
    

---

## \# Point

-   게임의 중간 상태는 각 구슬의 위치와 이전에 보드를 기울인 방향으로 정의할 수 있다
    
-   모든 경우의 수를 해보는 것은 BFS 로 구현했다  
    보드를 기울인 횟수도 상태에 저장할 수 있지만 그냥 BFS 밖의 변수로 셌다
    
-   두 구슬 중 하나만 빠져도 게임은 종료된다  
    즉, 게임이 계속 진행되기 위해서는 두 구슬 모두 구멍에 빠지지 않아야 한다
    
-   기울이는 도중 어떤 구슬이 구멍에 빠졌다면 그 구슬은 멈춘 것으로 보아야 한다
    
-   보드를 기울였을 때, 구슬의 움직임을 구현하는 부분이 실로 까다롭다  
    일단 각각의 구슬 모두 이동할 수 있으면 이동한 다음에 구멍에 빠졌는지 확인하는 식으로 구현했다  
    `(bool) isRMoved, isBMoved` 로 빨간 구슬과 파란 구슬의 이동 여부를 체크하고  
    `while (isRMoved || isBMoved)` 로 두 구슬이 움직이지 않았다면  
    보드를 기울이는 것을 멈춘다
    
-   구슬이 떨어졌는지 여부도 편의상 `(bool) isRFallen, isBFallen` 이라는 변수들로 다루었다  
    구멍의 위치와 구슬의 위치가 같으면 떨어진 것으로 간주하였다
    
-   두 구슬이 더 이상 움직이지 않는다면, 그때 구슬의 위치에 따라 게임의 상태가 결정된다  
    가능한 상태는 총 3가지로 다음과 같다  
    `파란 구슬이 떨어졌을 때` - 실패, 게임 종료  
    `파란 구슬이 떨어지지 않고 빨간 구슬만 떨어졌을 때` - 성공, 게임 종료  
    `두 구슬 모두 떨어지지 않았을 때` - 게임 계속  
    보드를 기울이는 함수가 각 상태를 뜻하는 고유번호와 구슬의 위치를 같이 반환하여  
    각 상태의 고유번호에 따라 추후에 어떻게 행동해야 될지를 결정하였다
    
-   좌표를 나타내는 구조체끼리 같은지 비교할 때,  
    편의를 위해 `==` 연산자를 오버로딩해서 사용했다
    
-   {0:남쪽, 1:동쪽, 2:서쪽, 3:북쪽} 으로 설정하여  
    이전 방향이 **x** 라면 **3-x** 로 반대방향을 쉽게 구할 수 있도록 했다
    
-   구슬을 움직일 때 좌표가 유효한지 검사는 하지 않았다  
    어차피 보드 위 모든 가장자리에 장애물이 있어서 그것만 검사하더라도  
    좌표가 보드 위의 유효한 좌표라는 것을 보장한다
    

---

#### \# Complexity - Time

-   가능한 경우의 수는 총 **2^10번**이다
    
-   보드를 한 번 기울이는 연산은 `while` 문에 따라서 결정되는데 기껏해야 O(10~20) 정도 될 것이다
    
-   O(1024 \* 20) <<< O(2 \* 10^8)
    
-   제한시간이 2초이므로 시간 내에 해결할 수 있다
    

---

## \# Warning

-   **예제 입력 7** 이 시뮬레이션 구현이 왜 어려운지를 보여준다  
    한번 기울일 때 구슬이 동시에 구멍에 빠지는 경우인데...  
    이것을 해결하려면 기울이는 도중에  
    구슬이 한 칸 한 칸 움직일 때마다 구멍에 빠졌는지 그렇지 않은지 확인해 줌으로써  
    다른 구슬의 움직임에 영향을 주는지 여부를 알아내야 한다
    
-   `while` 문 안에서 `(bool) isRMoved, isBMoved` 는  
    항상 초기에 `false` 로 초기화시켜 주어야 한다
    

---

## \# Code - C++ / Comment

```
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
char board[10][10];   // 장애물의 위치가 저장됨
int dy[4] = {+1, 0, 0, -1};   // 남, 동, 서, 북
int dx[4] = {0, +1, -1, 0};
struct Point { int y, x; };   // 좌표를 나타내는 구조체
struct Status { Point R, B; };   // 상태를 나타내는 구조체
Point O;   // 구멍의 위치가 저장됨
#define SUCCESS  1   // 가독성을 높이기 위한 상태 이름들
#define CONTINUE 0
#define FAIL    -1

// Set up : Functions Declaration
bool operator == (const Point &u, const Point &v);   // 좌표 비교의 편의성을 위해
pair<int,Status> move(Status C, int dir);   // 상태 C 에서 dir 방향으로 보드를 기울임

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
                board[i][j] = '.';   // board 에는 '.' 과 '#' 만 남게됨
            }
        }
    }

    // Process
    queue<pair<int,Status>> que;
    que.push({-1,{SR, SB}});   // 상태 초기화 (-1 은 이전방향이 없다는 뜻)

    int cnt = 0;   // 기울인 횟수는 이 변수로 셈
    while (not(que.empty())) {
        int size = que.size();
        cnt++;
        if (cnt > 10) break;
        while (size--) {
            Status C = que.front().second;   // 현재 상태
            int pd = que.front().first;   // 이전에 기울인 방향
            que.pop();

            for (int i=0; i<4; i++) {
                // 이전에 기울인 방향과 같거나 반대 방향이면 그냥 넘어감
                if (pd == i || 3-pd == i) continue;
                int code; Status A{};
                // 보드를 기울인 후 상태번호와 구슬의 위치를 받음
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
    Point CR = C.R; // current R
    Point CB = C.B; // current B

    bool isRMoved, isBMoved;
    bool isRFallen = false, isBFallen = false;

    do {
        isRMoved = false;
        isBMoved = false;

        if (not(isRFallen)) { // 현재 빨간구슬이 떨어지지 않았다면
            int nry = CR.y + dy[dir]; // new R y
            int nrx = CR.x + dx[dir]; // new R x
            Point NR{nry, nrx};
            // 다음 빨간구슬의 위치가 장애물이 아니고
            if (board[nry][nrx] != '#') {
                // 구멍이거나 현재 파란구슬이 있는 위치가 아니라면
                if (NR == O || not(NR == CB)) {
                    // 움직인다
                    isRMoved = true;
                    // 빨간구슬의 위치를 갱신한다
                    CR = NR;
                }
            }
        }
        if (not(isBFallen)) { // 현재 파란구슬이 떨어지지 않았다면
            int nby = CB.y + dy[dir]; // new B y
            int nbx = CB.x + dx[dir]; // new B x
            Point NB{nby, nbx};
            // 다음 파란구슬의 위치가 장애물이 아니고
            if (board[nby][nbx] != '#') {
                // 구멍이거나 현재 빨간구슬이 있는 위치가 아니라면
                if (NB == O || not(NB == CR)) {
                    // 움직인다
                    isBMoved = true;
                    // 파란구슬의 위치를 갱신한다
                    CB = NB;
                }
            }
        }

        // 각 구슬이 떨어졌는지 여부 확인
        isRFallen = (CR == O);
        isBFallen = (CB == O);
    } while (isRMoved || isBMoved);

    // 모든 구슬이 멈췄다, 그러니 구슬의 상태에 따라 게임의 상태를 판단한다
    // 파란구슬이 떨어졌으면
    if (isBFallen) {
        // 실패
        return {FAIL, {CR, CB}};
    // 파란구슬은 안떨어졌는데
    // 빨간구슬이 떨어졌으면
    } else if (isRFallen) {
        // 성공
        return {SUCCESS, {CR, CB}};
    // 빨간구슬도 안떨어졌으면
    } else {
        // 계속
        return {CONTINUE, {CR, CB}};
    }
}
```

---

## \# GitHub / No Comment

-   [C++](https://github.com/GGlifer/Problem_solving/commit/ef36ddd8bc73a3bfa37408f8bd3ade816059dae8)
-   Java / Not Yet
-   Python 3 / Not Yet

> 지적, 조언, 첨언 모두 환영합니다!