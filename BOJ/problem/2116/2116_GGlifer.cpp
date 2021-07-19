//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
enum Face { A, B, C, D, E, F };
struct Dice { int v2i[6+1], i2v[6]; };
int O[6] = { F, D, E, B, C, A };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    Dice D[N];
    for (int i=0; i<N; i++) {
        for (int j=0; j<6; j++) {
            int v; cin >> v;
            D[i].v2i[v] = j;
            D[i].i2v[j] = v;
        }
    }

    // Process
    function<int(int[6],int)> getSideMaxVal = [](int i2v[6], int down_idx){
        int mx = -1;
        for (int i=0; i<6; i++) {
            if (not(i == down_idx || i == O[down_idx])) {
                mx = max(mx, i2v[i]);
            }
        } return mx;
    };

    int ans = -1;
    for (int i=0; i<6; i++) {
        int down_idx = i;
        int tmp = getSideMaxVal(D[0].i2v, down_idx);
        int up_val = D[0].i2v[O[down_idx]];
        for (int j=1; j<N; j++) {
            down_idx = D[j].v2i[up_val];
            tmp += getSideMaxVal(D[j].i2v, down_idx);
            up_val = D[j].i2v[O[down_idx]];
        } ans = max(ans, tmp);
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

