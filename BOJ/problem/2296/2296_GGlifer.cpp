//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Building { int x, y, c; };
enum { $13, $24 };

// Set up : Functions Declaration
bool operator < (Building u, Building v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    Building B[N];
    for (int i=0; i<N; i++)
        cin >> B[i].x >> B[i].y >> B[i].c;

    // Process
    sort(B, B+N);

    int dp[N][2];
    for (int i=0; i<N; i++) {
        dp[i][$13] = dp[i][$24] = B[i].c;
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (B[j].y < B[i].y) {
                dp[i][$13] = max(dp[i][$13], dp[j][$13]+B[i].c);
            }
            if (B[j].y > B[i].y) {
                dp[i][$24] = max(dp[i][$24], dp[j][$24]+B[i].c);
            }
        }
    }

    int ans = *max_element(&dp[0][0], &dp[N-1][2]);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator < (Building u, Building v)
{
    return make_pair(u.x, u.y) < make_pair(v.x, v.y);
}

