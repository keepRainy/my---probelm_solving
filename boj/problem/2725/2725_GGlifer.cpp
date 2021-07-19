//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>
#include <numeric>

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

    // Process
   bool isVisible[1000+1][1000+1];
   memset(isVisible, false, sizeof(isVisible));
   isVisible[0][1] = isVisible[1][0] = isVisible[1][1] = true;

   for (int i=2; i<=1000; i++) {
       for (int j=1; j<i; j++) {
           int g = gcd(i, j);
           if (g == 1) {
               isVisible[i][j] = isVisible[j][i] = true;
           }
       }
   }

   long dp[1000+1];
   dp[1] = 3;
   for (int i=2; i<=1000; i++) {
       dp[i] = dp[i-1];
       for (int j=1; j<i; j++) {
           if (isVisible[i][j]) {
               dp[i] += 2;
           }
       }
   }

   // Set up : Input
   int C; cin >> C;

   while (C--) {
       int N; cin >> N;

       // Control : Output
       cout << dp[N] << endl;
   }
}

// Helper Functions
/* None */

