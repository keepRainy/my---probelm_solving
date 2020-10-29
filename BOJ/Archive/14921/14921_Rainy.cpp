//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>

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
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    sort(A, A+N);
    int s = 0, e = N-1;
    int ans = INF;
    while (s < e) {
        int sum = A[s] + A[e];
        ans = (abs(ans) > abs(sum)) ? sum : ans;
        if (ans == 0) break;
        (sum > 0) ? e-- : s++;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

