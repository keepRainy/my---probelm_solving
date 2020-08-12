//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <queue>
#include <cstring>
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
    int T; cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        // Process
        queue<int> que;
        bool isVisited[10000];
        memset(isVisited, false, sizeof(isVisited));
        int p[10000];
        memset(p, -1, sizeof(p));
        char m[10000];
        memset(m, 'X', sizeof(m));

        que.push(A);
        isVisited[A] = true;

        while (not(que.empty())) {
            int c = que.front(); que.pop();
            if (c == B) {
                break;
            }

            int d4 = c % 10;
            int d3 = c / 10 % 10;
            int d2 = c / 100 % 10;
            int d1 = c / 1000 % 10;

            int v;
            v = (2 * c) % 10000;
            if (not(isVisited[v])) {
                isVisited[v] = true;
                p[v] = c;
                m[v] = 'D';
                que.push(v);
            }

            v = (c + 10000 - 1) % 10000;
            if (not(isVisited[v])) {
                isVisited[v] = true;
                p[v] = c;
                m[v] = 'S';
                que.push(v);
            }

            v = c % 1000 * 10 + d1;
            if (not(isVisited[v])) {
                isVisited[v] = true;
                p[v] = c;
                m[v] = 'L';
                que.push(v);
            }

            v = c / 10 + 1000 * d4;
            if (not(isVisited[v])) {
                isVisited[v] = true;
                p[v] = c;
                m[v] = 'R';
                que.push(v);
            }
        }

        // Control : Output
        stack<char> st;
        while (p[B] != -1) {
            st.push(m[B]);
            B = p[B];
        }
        while (not(st.empty())) {
            cout << st.top(); st.pop();
        } cout << endl;
    }
}

// Helper Functions
/* None */
