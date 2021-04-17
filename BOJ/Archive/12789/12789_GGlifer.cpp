//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <stack>
#include <queue>

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
    queue<int> que;
    for (int i=0; i<N; i++) {
        int no; cin >> no;
        que.push(no);
    }

    // Process
    stack<int> st;

    int c = 1;
    bool isPossible = true;
    while (not(que.empty()) || not(st.empty())) {
        int f = (que.empty()) ? -1 : que.front();
        int t = (st.empty()) ? -1 : st.top();

        if (f > 0 && f == c) {
            que.pop();
            c++;
            continue;
        }

        if (t > 0 && t == c) {
            st.pop();
            c++;
            continue;
        }

        if (f > 0 && f != c) {
            if (t > 0 && t < f) {
                isPossible = false;
                break;
            }
            st.push(f);
            que.pop();
        }
    }

    // Control : Output
    cout << ((isPossible) ? "Nice" : "Sad") << endl;
}

// Helper Functions
/* None */

