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
    int H[N];
    for (int i=0; i<N; i++)
        cin >> H[i];

    // Process
    stack<int> st;

    long ans = 0;
    for (int i=0; i<N; i++) {
        while (not(st.empty()) && H[i] >= H[st.top()]) {
            ans += st.size()-1;
            st.pop();
        } st.push(i);
    }

    while (not(st.empty())) {
        ans += st.size()-1;
        st.pop();
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

