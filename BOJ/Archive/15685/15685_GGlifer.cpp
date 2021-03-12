//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
enum { R, U, L, D };
int dx[4] = {+1, 0, -1, 0};
int dy[4] = {0, -1, 0, +1};
int T[4] = {U, L, D, R};

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    bool A[100+1][100+1];
    memset(A, false, sizeof(A));
    for (int i=0; i<N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        // Process
        A[x][y] = true;

        vector<int> D;
        D.push_back(d);
        for (int j=0; j<g; j++) {
            vector<int> tmp = D;
            for_each(tmp.begin(), tmp.end(), [](int &_d){ _d = (_d+1)%4; });
            reverse(tmp.begin(), tmp.end());
            move(tmp.begin(), tmp.end(), back_inserter(D));
        }
        for (int _d : D) {
            x += dx[_d];
            y += dy[_d];
            A[x][y] = true;
        }
    }

    // Process
    int ans = 0;
    for (int i=0; i<=99; i++) {
        for (int j=0; j<=99; j++) {
            if (A[i][j] && A[i+1][j] && A[i][j+1] && A[i+1][j+1]) {
                ans++;
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

