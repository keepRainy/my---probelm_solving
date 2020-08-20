//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
long f(int n);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;

    int cmd; cin >> cmd;
    if (cmd == 1) {
        long k; cin >> k;

        // Process
        vector<int> A(N, -1);
        vector<int> nums;
        for (int i=1; i<=N; i++) {
            nums.push_back(i);
        }

        k--;
        for (int i=0; i<N; i++) {
            long q = k / f(N-1-i);
            A[i] = nums[q];
            nums.erase(nums.begin()+q);
            k %= f(N-1-i);
        }

        // Control : Output
        for (int n : A) {
            cout << n << ' ';
        } cout << endl;
    }
    else if (cmd == 2) {
        int A[N];
        for (int i=0; i<N; i++) {
            cin >> A[i];
        }

        // Process
        vector<int> nums;
        for (int i=1; i<=N; i++) {
            nums.push_back(i);
        }

        long k = 0;
        for (int i=0; i<N; i++) {
            auto pos = find(nums.begin(), nums.end(), A[i]);
            int idx = pos - nums.begin();
            k += idx * f(N-1-i);
            nums.erase(pos);
        } k++;

        // Control : Output
        cout << k << endl;
    }
}

// Helper Functions
long f(int n)
{
    if (n == 0) return 1;
    return (long)n * f(n-1);
}
