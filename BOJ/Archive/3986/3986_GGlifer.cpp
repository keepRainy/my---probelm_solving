//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
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
    int N; cin >> N;
    string W[N];
    for (int i=0; i<N; i++)
        cin >> W[i];

    // Process
    int ans = 0;
    for (int i=0; i<N; i++) {
        stack<char> st;
        for (char c : W[i]) {
            if (st.empty() || st.top() != c) {
                st.push(c);
            } else {
                st.pop();
            }
        }

        if (st.empty()) ans++;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

