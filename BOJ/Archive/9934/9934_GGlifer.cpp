//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int K;
int A[1023+1];
vector<int> L[10+1];

// Set up : Functions Declaration
void f(int s, int e, int lev);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> K;
    int S = pow(2,K)-1;
    for (int i=1; i<=S; i++)
        cin >> A[i];

    // Process
    f(1, S, 1);

    // Control : Output
    for (int i=1; i<=K; i++) {
        for (int n : L[i]) {
            cout << n << ' ';
        } cout << endl;
    }
}

// Helper Functions
void f(int s, int e, int lev)
{
    int m = (s+e) / 2;
    L[lev].push_back(A[m]);
    if (s == e) return;

    f(s, m-1, lev+1);
    f(m+1, e, lev+1);
}
