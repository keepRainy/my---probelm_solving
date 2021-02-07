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
    int T; cin >> T;

    while (T--) {
        int K; cin >> K;

        // Process
        map<int,int> M;
        for (int i=0; i<K; i++) {
            char type; int n;
            cin >> type >> n;

            if (type == 'I') { M[n]++; }
            else if (type == 'D' && n == 1) {
                if (M.empty()) continue;
                int maxi = (--M.end())->first;
                int &num = (--M.end())->second;
                num--;
                if (num == 0) { M.erase(maxi); }
            }
            else if (type == 'D' && n == -1) {
                if (M.empty()) continue;
                int mini = (M.begin())->first;
                int &num = (M.begin())->second;
                num--;
                if (num == 0) { M.erase(mini); }
            }
        }

        // Control : Output
        if (M.empty())
            cout << "EMPTY" << endl;
        else
            cout << (--M.end())->first << ' ' << (M.begin())->first << endl;
    }
}

// Helper Functions
/* None */

