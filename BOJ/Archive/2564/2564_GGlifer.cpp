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
struct Point { int r, c, p; };
typedef pair<int,int> pii;

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int C, R;
    cin >> C >> R;
    int N; cin >> N;
    Point S[N+1];
    for (int i=0; i<N+1; i++) {
        int p, d;
        cin >> p >> d;
        int r, c;
        switch (p) {
            case 1: r = 0; c = d; break;
            case 2: r = R; c = d; break;
            case 3: r = d; c = 0; break;
            case 4: r = d; c = C; break;
            default: throw invalid_argument("Invalid Position");
        } S[i] = {r, c, p};
    }

    // Process
    int xr = S[N].r, xc = S[N].c, xp = S[N].p;
    int ans = 0;
    for (int i=0; i<N; i++) {
        int sr = S[i].r, sc = S[i].c, sp = S[i].p;
        pii pos = {min(xp,sp), max(xp,sp)};
        int dy = abs(xr-sr), dx = abs(xc-sc);
        if (pos == pii{1,2}) {
            dx = min(xc+sc, 2*C-(xc+sc));
        }
        if (pos == pii{3,4}) {
            dy = min(xr+sr, 2*R-(xr+sr));
        } ans += dx+dy;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

