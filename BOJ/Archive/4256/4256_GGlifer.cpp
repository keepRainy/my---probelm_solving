//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
int P[1000], I[1000], O[1000];

// Set up : Functions Declaration
void postorder(int sp, int ep, int si, int ei);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++)
            cin >> P[i];
        for (int i=0; i<N; i++) {
            cin >> I[i];
            O[I[i]] = i;
        }

        // Control : Output
        postorder(0, N-1, 0, N-1);
        cout << endl;
    }
}

// Helper Functions
void postorder(int sp, int ep, int si, int ei)
{
    int v = P[sp];
    int idx = O[v];
    int ln = idx - si;
    int rn = ei - idx;

    int lsp = sp+1, lep = sp+ln, lsi = si, lei = idx-1;
    if (lsp <= lep && lsi <= lei)
        postorder(lsp, lep, lsi, lei);

    int rsp = ep-rn+1, rep = ep, rsi = idx+1, rei = ei;
    if (rsp <= rep && rsi <= rei)
        postorder(rsp, rep, rsi, rei);

    cout << v << ' ';
}
