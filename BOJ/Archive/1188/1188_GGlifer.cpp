//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M;

// Set up : Functions Declaration
int cut(int n, int m);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M;

    // Process
    int ans = cut(N, M);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int cut(int n, int m)
{
    n %= m;
    if (n == 0) return 0;
    return n + cut(n, m-n);
}
