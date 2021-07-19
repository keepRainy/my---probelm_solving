//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

// Set up : Global Variables


// Set up : Functions Declaration
bool isPrime(int n);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;

    // Process
    queue<int> que;

    int cnt = 1;
    que.push(2);
    que.push(3);
    que.push(5);
    que.push(7);

    int D[4] = {1, 3, 7, 9};
    while (cnt++ < N) {
        int size = que.size();
        while (size--) {
            int c = que.front(); que.pop();
            for (int d : D) {
                int n = 10*c + d;
                if (isPrime(n)) {
                    que.push(n);
                }
            }
        }
    }

    // Control : Output
    while (not(que.empty())) {
        cout << que.front() << endl;
        que.pop();
    }
}

// Helper Functions
bool isPrime(int n)
{
    if (n == 0 || n == 1) return false;
    for (int i=2; i*i<=n; i++) {
        if (n%i == 0) return false;
    } return true;
}
