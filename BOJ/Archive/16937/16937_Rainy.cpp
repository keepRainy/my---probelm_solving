//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int H, W;

// Set up : Functions Declaration
bool isFeasible(int r1, int c1, int r2, int c2);
bool isPossible(int r1, int c1, int r2, int c2);

int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> H >> W;
    int N; cin >> N;
    int R[N], C[N];
    for (int i=0; i<N; i++) {
        cin >> R[i] >> C[i];
    }

    // Process
    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            int r1 = R[i], c1 = C[i];
            int r2 = R[j], c2 = C[j];
            if (isPossible(r1, c1, r2, c2)) {
                ans = max(ans, r1*c1 + r2*c2);
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool isFeasible(int r1, int c1, int r2, int c2)
{
    if (r1+r2 <= H && max(c1,c2) <= W) return true;
    if (max(r1,r2) <= H && c1+c2 <= W) return true;
    return false;
}

bool isPossible(int r1, int c1, int r2, int c2)
{
    if (isFeasible(r1, c1, r2, c2)) return true;
    if (isFeasible(c1, r1, r2, c2)) return true;
    if (isFeasible(r1, c1, c2, r2)) return true;
    if (isFeasible(c1, r1, c2, r2)) return true;
    return false;
}
