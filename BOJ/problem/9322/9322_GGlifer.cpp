//
//  Codeforces
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <map>

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

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        string PK1[N], PK2[N], C[N];
        for (int i=0; i<N; i++)
            cin >> PK1[i];
        for (int i=0; i<N; i++)
            cin >> PK2[i];
        for (int i=0; i<N; i++)
            cin >> C[i];

        // Process
        map<int,string> i2w;
        for (int i=0; i<N; i++) {
            i2w[i] = PK2[i];
        }
        map<string,int> w2i;
        for (int i=0; i<N; i++) {
            w2i[PK1[i]] = i;
        }

        string D[N];
        for (int i=0; i<N; i++) {
            D[w2i[i2w[i]]] = C[i];
        }

        // Control : Output
        for (int i=0; i<N; i++) {
            cout << D[i] << ' ';
        } cout << endl;

    }
}

// Helper Functions
/* None */

