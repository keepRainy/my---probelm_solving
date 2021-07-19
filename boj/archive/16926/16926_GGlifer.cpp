//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <deque>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point {int y, x; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, M, R;
    cin >> N >> M >> R;
    int A[N][M];
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> A[i][j];

    // Process
    for (int i=0; i<min(N,M)/2; i++) {
        int n = N-2*i, m = M-2*i;
        int a = 2*n + 2*m - 4;
        int r = R % a;
        int lly = i+n-1, llx = i;
        int ury = i, urx = i+m-1;
        deque<Point> P;
        deque<int> V;
        for (int y=ury; y<lly; y++) { P.push_back({y, llx}), V.push_back(A[y][llx]); }
        for (int x=llx; x<urx; x++) { P.push_back({lly, x}), V.push_back(A[lly][x]); }
        for (int y=lly; y>ury; y--) { P.push_back({y, urx}), V.push_back(A[y][urx]); }
        for (int x=urx; x>llx; x--) { P.push_back({ury, x}), V.push_back(A[ury][x]); }
        for (int j=0; j<r; j++) { V.push_front(V.back()); V.pop_back(); }
        for (int j=0; j<a; j++) {
            auto [y, x] = P.front(); P.pop_front();
            int v = V.front(); V.pop_front();
            A[y][x] = v;
        }
    }

    // Control : Output
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << A[i][j] << ' ';
        } cout << endl;
    }
}

// Helper Functions
/* None */
