//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Wire { int a, b; };

// Set up : Functions Declaration
bool operator < (Wire u, Wire v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    vector<Wire> W(N);
    for (int i=0; i<N; i++)
        cin >> W[i].a >> W[i].b;

    // Process
    sort(W.begin(), W.end());
    vector<int> dp(N, 1);
    int ans = N-1;
    for (int i=1; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (W[i].b > W[j].b && dp[i] < dp[j]+1) {
                dp[i] = dp[j]+1;
                ans = min(ans, N-dp[i]);
            }
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (Wire u, Wire v)
{
    return u.a < v.a;
}
