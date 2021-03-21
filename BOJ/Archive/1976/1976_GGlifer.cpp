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
int P[200+1], R[200+1];

// Set up : Functions Declaration
int find(int x);
void merge(int x, int y);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int M; cin >> M;
    for (int i=1; i<=N; i++) { P[i] = i, R[i] = 1; }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            bool isConn; cin >> isConn;

            // Process
            if (isConn) {
                if (find(i) != find(j)) {
                    merge(i, j);
                }
            }
        }
    }

    // Set up: Input
    int C[M];
    for (int i=0; i<M; i++)
        cin >> C[i];

    // Process
    bool isPossible = true;
    for (int i=0; i<M-1; i++) {
        if (find(C[i]) != find(C[i+1])) {
            isPossible = false;
            break;
        }
    }

    // Control : Output
    cout << ((isPossible) ? "YES" : "NO") << endl;
}

// Helper Functions
int find(int x)
{
    if (P[x] == x) return x;
    return P[x] = find(P[x]);
}

void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;

    if (R[x] < R[y]) swap(x, y);
    P[y] = x;
    if (R[x] == R[y]) R[x]++;
}

