//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <numeric>
// #include <iomanip>

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
    long A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];
    int M; cin >> M;
    long B[M];
    for (int i=0; i<M; i++)
        cin >> B[i];

    // Process
    long ans = 1;
    bool isBig = false;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            long gij = gcd(A[i], B[j]);
            ans *= gij;
            if (ans >= 1'000'000'000) {
                isBig = true;
                ans %= 1'000'000'000;
            }
            A[i] /= gij;
            B[j] /= gij;
        }
    }

    // Control : Output
    if (isBig)
        printf("%09ld\n", ans);
        // cout << setfill('0') << setw(9) << ans << endl;
    else
        cout << ans << endl;
}

// Helper Functions
/* None */

