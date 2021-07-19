//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
int A[20+1][20+1];
int B[20+1][20+1];

// Set up : Functions Declaration
int diff(int d1, int d2, int x, int y);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            cin >> A[i][j];

    // Process
    int ans = -1;
    for (int d1=1; d1<N; d1++) {
        for (int d2=1; d2<N; d2++) {
            for (int x=1; x+d1+d2<=N; x++) {
                for (int y=1+d1; y+d2<=N; y++) {
                    int tmp = diff(d1, d2, x, y);
                    if (ans == -1 || ans > tmp) {
                        ans = tmp;
                    }
                }
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int diff(int d1, int d2, int x, int y)
{
    memset(B, 0, sizeof(B));
    for (int i=0; i<=d1; i++)
        B[x+i][y-i] = 5;
    for (int i=0; i<=d2; i++)
        B[x+i][y+i] = 5;
    for (int i=0; i<=d2; i++)
        B[x+d1+i][y-d1+i] = 5;
    for (int i=0; i<=d1; i++)
        B[x+d2+i][y+d2-i] = 5;

    for (int i=0; i<d1; i++) {
        for (int j=1; B[x+i+j][y-i] != 5; j++) {
            B[x+i+j][y-i] = 5;
        }
    }
    for (int i=1; i<d2; i++) {
        for (int j=1; B[x+i+j][y+i] != 5; j++) {
            B[x+i+j][y+i] = 5;
        }
    }

    int s1, s2, s3, s4, s5;
    s1 = s2 = s3 = s4 = s5 = 0;
    for (int r=1; r<=N; r++) {
        for (int c=1; c<=N; c++) {
            if (B[r][c] == 5)
                s5 += A[r][c];
            else if (1 <= r && r < x+d1 && 1 <= c && c <= y)
                s1 += A[r][c];
            else if (1 <= r && r <= x+d2 && y < c && c <= N)
                s2 += A[r][c];
            else if (x+d1 <= r && r <= N && 1 <= c && c < y-d1+d2)
                s3 += A[r][c];
            else if (x+d2 < r && r <= N && y-d1+d2 <= c && c <= N)
                s4 += A[r][c];
        }
    }

    auto S = {s1, s2, s3, s4, s5};
    return max(S) - min(S);
}
