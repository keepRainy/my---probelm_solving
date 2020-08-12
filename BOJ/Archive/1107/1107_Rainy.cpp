//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
bool broken[10];

// Set up : Functions Declaration
int isPossible(int ch);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int M; cin >> M;
    if (M > 0) {
        for (int i=0; i<M; i++) {
            int n; cin >> n;
            broken[n] = true;
        }
    }

    // Process
    int ans = abs(100 - N);
    int scope = max(2*N, 2*100);
    for (int i=0; i<=scope; i++) {
        int r = isPossible(i);
        if (r != -1) {
            ans = min(ans, r + abs(i - N));
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int isPossible(int ch)
{
    if (ch == 0) {
        return (not(broken[0])) ? 1 : -1;
    }

    int clicks = 0;
    while (ch) {
        int n = ch % 10;
        if (broken[n]) return -1;
        clicks++;
        ch /= 10;
    }

    return clicks;
}