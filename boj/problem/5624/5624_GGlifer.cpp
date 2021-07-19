//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <map>
#include <cstring>

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
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    int ofs = 200'000;
    bool S2[2*ofs+1];
    memset(S2, false, sizeof(S2));
    S2[A[0]+A[0]+ofs] = true;

    int ans = 0;
    for (int i=1; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (S2[A[i]-A[j]+ofs]) {
                ans++;
                break;
            }
        }

        for (int j=0; j<=i; j++) {
            S2[A[i]+A[j]+ofs] = true;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

