//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
typedef pair<string,int> psi;

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    map<string,int> M;
    for (int i=0; i<N; i++) {
        string name; cin >> name;
        M[name]++;
    }

    // Process
    vector<pair<string,int>> V(M.begin(), M.end());
    sort(V.begin(), V.end(), [](psi &u, psi &v){
        string u_name = u.first, v_name = v.first;
        int u_count = u.second, v_count = v.second;
        return make_pair(-u_count, u_name) < make_pair(-v_count, v_name);
    });

    // Control : Output
    cout << V.begin()->first << endl;
}

// Helper Functions
/* None */

