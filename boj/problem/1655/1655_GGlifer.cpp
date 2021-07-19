//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
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

    // Process
    priority_queue<int> low; /* MaxHeap */
    priority_queue<int, vector<int>, greater<>> high; /* MinHeap */

    for (int i=0; i<N; i++) {
        int n; cin >> n;

        (low.empty() || n <= low.top()) ? low.push(n) : high.push(n);

        if (low.size() > high.size()+1) {
            high.push(low.top());
            low.pop();
        }

        if (high.size() > low.size()) {
            low.push(high.top());
            high.pop();
        }

        // Control : Output
        cout << low.top() << endl;
    }
}

// Helper Functions
/* None */

