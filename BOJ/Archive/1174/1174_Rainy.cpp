//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
#define MAX 9876543210

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
    vector<long> desc;
    queue<long> que;
    for (int i=0; i<=9; i++) {
        desc.push_back(i);
        que.push(i);
    }

    while (not(que.empty())) {
        long c = que.front(); que.pop();

        for (int i=0; i<c%10; i++) {
            long n = 10*c + i;
            desc.push_back(n);
            que.push(n);
        }
    }

    // Control : Output
    cout << ((N > desc.size()) ? -1 : desc[N-1]) << endl;
}

// Helper Functions
/* None */

