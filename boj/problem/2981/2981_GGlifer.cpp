//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
int gcd(int a, int b);


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
    sort(A, A+N);
    int M = A[1]-A[0];
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            M = gcd(M, A[j]-A[i]);
        }
    }

    set<int> D;
    for (int i=1; i*i<=M; i++) {
        if (M%i == 0) {
            D.insert(i);
            D.insert(M/i);
        }
    } D.erase(1);

    // Control : Output
    for (int d : D) {
        cout << d << ' ';
    } cout << endl;
}

// Helper Functions
int gcd(int a, int b)
{
    int r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    } return a;
}
