//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, L, R, X;
int A[15];
#define INF 987654321

// Set up : Functions Declaration
int dfs(int i, int cnt, int sum, int easiest, int hardest);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> L >> R >> X;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    // Process
    int ans = dfs(0, 0, 0, INF, -1);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int dfs(int i, int cnt, int sum, int easiest, int hardest)
{
    if (i == N) {
        if (cnt < 2) return 0;
        if (sum < L || sum > R) return 0;
        if (hardest - easiest < X) return 0;
        return 1;
    }

    int ret = 0;
    ret += dfs(i+1, cnt, sum, easiest, hardest);
    ret += dfs(i+1, cnt+1, sum+A[i], min(easiest,A[i]), max(hardest,A[i]));

    return ret;
}
