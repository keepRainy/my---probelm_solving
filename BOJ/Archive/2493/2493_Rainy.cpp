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
#define INF 987654321

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int T[N+1];
    for (int i=1; i<=N; i++) {
        cin >> T[i];
    } T[0] = INF;

    // Process
    int A[N+1];
    stack<int> st;
    st.push(0);
    for (int i=1; i<=N; i++) {
        if (T[i] < T[st.top()]) {
            A[i] = st.top();
            st.push(i);
        } else {
            while (T[i] > T[st.top()]) {
                st.pop();
            } A[i] = st.top();
            st.push(i);
        }
    }

    while (true) {
        int curr = st.top();
        st.pop();
        if (st.empty()) break;
        int prev = st.top();
        A[curr] = prev;
    }

    // Control : Output
    for (int i=1; i<=N; i++) {
        cout << A[i] << ' ';
    } cout << endl;
}

// Helper Functions
/* None */

