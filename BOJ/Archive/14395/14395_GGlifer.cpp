//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <queue>
#include <map>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int s, t;
    cin >> s >> t;

    // Control : Output
    if (s == t) {
        cout << 0 << endl;
        exit(0);
    }

    // Process
    map<long,string> dp;
    queue<long> que;
    que.push(s);
    dp[s] = "";

    string OP[] = {"*", "+", "-", "/"};
    while (not(que.empty())) {
        long c = que.front();
        que.pop();
        if (c == 0) continue;
        if (c == t) break;

        string e = dp[c];
        long N[] = {c*c, c+c, c-c, c/c};
        for (int i=0; i<4; i++) {
            string op = OP[i];
            long n = N[i];
            if (n <= t && not(dp.contains(n))) {
                dp[n] = e + op;
                que.push(n);
            }
        }
    }

    // Control : Output
    cout << ((dp[t].empty()) ? to_string(-1) : dp[t]) << endl;
}

// Helper Functions
/* None */

