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
    string s; cin >> s;

    // Process
    stack<char> st;
    int ans = 0, offset = 1;
    bool isRight = true;
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        if (c == '(') { offset *= 2; st.push('('); }
        if (c == '[') { offset *= 3; st.push('['); }
        if (c == ')') {
            if (st.empty() || st.top() != '(') {
                isRight = false;
                break;
            }
            offset /= 2;
            if (i > 0 && s[i-1] == '(') {
                ans += offset * 2;
            }
            st.pop();
        }
        if (c == ']') {
            if (st.empty() || st.top() != '[') {
                isRight = false;
                break;
            }
            offset /= 3;
            if (i > 0 && s[i-1] == '[') {
                ans += offset * 3;
            }
            st.pop();
        }
    }
    if (not(st.empty())) {
        isRight = false;
    }

    // Control : Output
    cout << ((isRight) ? ans : 0) << endl;
}

// Helper Functions
/* None */

