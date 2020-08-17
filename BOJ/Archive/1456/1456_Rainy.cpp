//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
bool isPrime[10000000+1];

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Process
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    vector<long> primes;
    for (int i=2; i<=10000000; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j=i+i; j<=10000000; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    // Set up : Input
    long A, B;
    cin >> A >> B;

    long ans = 0;
    for (long prime : primes) {
        long val = prime;
        while (val <= B/prime) {
            if (val >= (A+prime-1)/prime) {
                ans++;
            } val *= prime;
        }

//      long double val = prime * prime;
//      while (val <= B) {
//          if (val >= A) {
//              ans++;
//          } val *= prime;
//      }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

