//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Info { int cnt, ord; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, C;
    cin >> N >> C;
    int A[N];
    for (int i=0; i<N; i++)
        cin >> A[i];

    // Process
    map<int,Info> M;
    for (int i=0; i<N; i++) {
        int n = A[i];
        if (M.find(n) == M.end()) {
            M[n].ord = i;
        } M[n].cnt++;
    }

    sort(A, A+N, [&M](int u, int v){
        Info ui = M[u], vi = M[v];
        return make_pair(-ui.cnt, ui.ord) < make_pair(-vi.cnt, vi.ord);
    });

    // Control : Output
    for (int e : A) {
        cout << e << ' ';
    }
}

// Helper Functions
/* None */

