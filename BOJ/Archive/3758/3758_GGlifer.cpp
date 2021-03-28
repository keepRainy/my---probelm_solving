//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Team { int id; map<int,int> board; int score{}, cnt{}, last{}; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int n, k, t, m;
        cin >> n >> k >> t >> m;
        Team TM[n+1];
        for (int i=1; i<=n; i++) { TM[i].id = i; }
        for (int o=0; o<m; o++) {
            int i, j, s;
            cin >> i >> j >> s;

            Team &tm = TM[i];
            tm.cnt++;
            tm.last = o;
            if (tm.board[j] < s) {
                tm.score += s - tm.board[j];
                tm.board[j] = s;
            }
        }

        // Process
        sort(TM+1, TM+(n+1), [](Team &u, Team &v){
            return make_tuple(-u.score, u.cnt, u.last) < make_tuple(-v.score, v.cnt, v.last);
        });

        int ans = find_if(TM+1, TM+(n+1), [t](const Team &tm){ return tm.id == t; }) - TM;

        // Control : Output
        cout << ans << endl;
    }
}

// Helper Functions
/* None */
