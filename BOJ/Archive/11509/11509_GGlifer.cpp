//
//  BOJ
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
    int N; cin >> N;
    int H[N];
    for (int i=0; i<N; i++) {
        cin >> H[i];
    }

    // Process
    map<int,int> arrows;
    int ans = 0;
    for (int i=0; i<N; i++) {
        int h = H[i];
        if (arrows[h] > 0) {
            arrows[h]--;
            arrows[h-1]++;
        } else {
            ans++;
            arrows[h-1]++;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

