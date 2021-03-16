//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <set>
#include <algorithm>

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
    int N; cin >> N;
    string W[N];
    for (int i=0; i<N; i++)
        cin >> W[i];

    // Process
    multiset<char> fs(W[0].begin(), W[0].end());

    int ans = 0;
    for (int i=1; i<N; i++) {
        multiset<char> is(W[i].begin(), W[i].end());

        multiset<char> f_is, i_fs;
        set_difference(fs.begin(), fs.end(), is.begin(), is.end(), inserter(f_is, f_is.begin()));
        set_difference(is.begin(), is.end(), fs.begin(), fs.end(), inserter(i_fs, i_fs.begin()));

        if (f_is.size() <= 1 && i_fs.size() <= 1) ans++;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

