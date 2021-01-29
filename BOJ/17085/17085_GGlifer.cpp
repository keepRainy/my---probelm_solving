//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;
char A[15][15];
bool isChecked[15][15];

// Set up : Functions Declaration
int getSize(int y, int x);
void check(int y, int x, int s);
void uncheck(int y, int x, int s);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> A[i][j];

    // Process
    int ans = -1;
    for (int y1=0; y1<N; y1++) {
        for (int x1=0; x1<M; x1++) {
            if (A[y1][x1] != '#') continue;
            int s1 = getSize(y1, x1);
            check(y1, x1, s1);
            for (int y2=0; y2<N; y2++) {
                for (int x2=0; x2<M; x2++) {
                    if (A[y2][x2] != '#') continue;
                    int s2 = getSize(y2, x2);
                    ans = max(ans, (4*s1+1)*(4*s2+1));
                }
            }
            uncheck(y1, x1, s1);
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int getSize(int y, int x)
{
    int s = min(min(y, N-y-1), min(x, M-x-1));
    for (int i=1; i<=s; i++) {
        if (A[y+i][x] != '#' || isChecked[y+i][x]) return i-1;
        if (A[y-i][x] != '#' || isChecked[y-i][x]) return i-1;
        if (A[y][x+i] != '#' || isChecked[y][x+i]) return i-1;
        if (A[y][x-i] != '#' || isChecked[y][x-i]) return i-1;
    } return s;
}

void check(int y, int x, int s)
{
    isChecked[y][x] = true;
    for (int i=1; i<=s; i++) {
        isChecked[y+i][x] = true;
        isChecked[y-i][x] = true;
        isChecked[y][x+i] = true;
        isChecked[y][x-i] = true;
    }
}

void uncheck(int y, int x, int s)
{
    isChecked[y][x] = false;
    for (int i=1; i<=s; i++) {
        isChecked[y+i][x] = false;
        isChecked[y-i][x] = false;
        isChecked[y][x+i] = false;
        isChecked[y][x-i] = false;
    }
}
