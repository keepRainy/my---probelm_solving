//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Ant { char ltr, dir; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N1, N2;
    cin >> N1 >> N2;
    string G1; cin >> G1;
    string G2; cin >> G2;
    int T; cin >> T;

    // Process
    int L1 = G1.length();
    int L2 = G2.length();
    Ant A[L1+L2];
    for (int i=0; i<L1; i++) {
        A[(L1-1)-i] = {G1[i], 'r'};
    }
    for (int i=0; i<L2; i++) {
        A[L1+i] = {G2[i], 'l'};
    }

    int L = L1 + L2;
    while (T--) {
        for (int i=0; i<L-1; i++) {
            if (A[i].dir == 'r' && A[i+1].dir == 'l') {
                swap(A[i], A[i+1]);
                i++;
            }
        }
    }

    // Control : Output
    for (auto &a : A) {
        cout << a.ltr;
    }
}

// Helper Functions
/* None */

