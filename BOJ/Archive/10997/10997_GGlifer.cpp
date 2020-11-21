//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
char B[4*100-1][4*100-3];
int my, mx;
int dy[4] = {0, +1, 0, -1};
int dx[4] = {+1, 0, -1, 0};

// Set up : Functions Declaration
void f(int n);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;

    // Control : Output
    if (N == 1) {
        cout << "*" << endl;
        exit(0);
    }

    // Process
    memset(B, ' ', sizeof(B));
    my = 2*N-1;
    mx = 2*N-2;
    B[my+1][mx] = B[my][mx] = B[my-1][mx] = '*';
    f(2);

    // Control : Output
    int H = 4*N-1, W = 4*N-3;
    for (int i=0; i<H; i++) {
        string line;
        for (int j=0; j<W; j++) {
            line.push_back(B[i][j]);
        } while (line.back() == ' ') line.pop_back();
        cout << line << endl;
    }
}

// Helper Functions
void f(int n)
{
    int sy = my - (2*n-1);
    int sx = mx - (2*n-2);
    int count[4] = {4*n-3, 4*n-1, 4*n-3, 4*n-1};
    for (int i=0; i<4; i++) {
        int cnt = count[i];
        while (cnt--) {
            B[sy][sx] = '*';
            if (cnt > 0) { sy += dy[i], sx += dx[i]; }
        }
    }

    swap(B[my-(2*n-2)][mx+(2*n-2)], B[my-(2*n-3)][mx+(2*n-3)]);

    if (n == N) return;
    f(n+1);
}
