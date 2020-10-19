//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <cmath>

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
    int N, M;
    cin >> N >> M;
    int T[N];
    for (int i=0; i<N; i++)
        cin >> T[i];

    // Process
    long l = 1, r = pow(10, 18);
    long ans = -1;
    while (l <= r) {
        long m = (l + r) / 2;
        long cnt = 0;
        for (int i=0; i<N; i++) {
            cnt += m / T[i];
            if (cnt >= M) break;
       }

       if (cnt >= M) {
           ans = m;
           r = m-1;
       } else {
           l = m+1;
       }
   }

   // Control : Output
   cout << ans << endl;
}

// Helper Functions
/* None */

