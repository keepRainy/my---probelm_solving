//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <stack>

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
    int tc = 0;
    while (true) {
        string s; cin >> s;
        if (s.front() == '-') break;
        tc++;

        // Process
        int lp = 0, rp = 0;
        stack<char> st;
        for (char c : s) {
            if (c == '{') {
                st.push(c);
                lp++;
            } else {
                if (not(st.empty()) && st.top() == '{') {
                    st.pop();
                    lp--;
                } else {
                    st.push(c);
                    rp++;
                }
            }
        }

        int ans = 0;
        ans += lp/2; ans += rp/2;
        ans += lp%2; ans += rp%2;

        // Control : Output
        printf("%d. %d\n", tc, ans);
    }
}

// Helper Functions
/* None */

