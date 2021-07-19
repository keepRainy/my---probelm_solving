//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
bool isPrime(long num);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Test
    // int cnt = 0;
    // long num = 1;
    // while (cnt < 500'000) {
    //     num++;
    //     if (isPrime(num)) cnt++;
    // } cout << num << endl;

    // Set up : Input
    int K; cin >> K;

    // Process
    int N = 7368787;
    bool isPrime[N+1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    vector<int> primes;
    for (int i=2; i<=N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j=2*i; j<=N; j+=i) {
                isPrime[j] = false;
            }
        }
    }

    // Control : Output
    cout << primes[K-1] << endl;
}

// Helper Functions
bool isPrime(long num)
{
    if (num == 0 || num == 1) return false;
    for (int i=2; i*i<=num; i++) {
        if (num%i == 0) return false;
    } return true;
}
