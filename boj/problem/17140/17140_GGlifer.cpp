//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int r, c, k;
int A[100+1][100+1];
int cr, cc;

// Set up : Functions Declaration
void op_R();
void op_C();


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> r >> c >> k;
    for (int i=1; i<=3; i++)
        for (int j=1; j<=3; j++)
            cin >> A[i][j];

    // Process
    cr = cc = 3;
    int time = 0;
    while (A[r][c] != k && time <= 100) {
        time++;
        (cr >= cc) ? op_R() : op_C();

    }

    // Control : Output
    cout << ((time > 100) ? -1 : time) << endl;
}

// Helper Functions
void op_R()
{

    for (int i=1; i<=cr; i++) {
        map<int,int> M;
        for (int j=1; j<=cc; j++) {
            if (A[i][j] == 0) continue;
            M[A[i][j]]++;
        }

        vector<pair<int,int>> V(M.begin(), M.end());
        sort(V.begin(), V.end(), [](auto &u, auto &v){
            return make_pair(u.second, u.first) < make_pair(v.second, v.first);
        });

        int s = V.size();

        for (int j=1; j<=cc; j++) { A[i][j] = 0; }
        for (int j=0; j<s && 2*j+2<=100; j++) {
            A[i][2*j+1] = V[j].first;
            A[i][2*j+2] = V[j].second;
        }

        cc = min(100, max(cc, 2*s));
    }
}

void op_C()
{
    for (int j=1; j<=cc; j++) {
        map<int,int> M;
        for (int i=1; i<=cr; i++) {
            if (A[i][j] == 0) continue;
            M[A[i][j]]++;
        }

        vector<pair<int,int>> V(M.begin(), M.end());
        sort(V.begin(), V.end(), [](auto &u, auto &v){
            return make_pair(u.second, u.first) < make_pair(v.second, v.first);
        });

        int s = V.size();

        for (int i=1; i<=cr; i++) { A[i][j] = 0; }
        for (int i=0; i<s && 2*i+2<=100; i++) {
            A[2*i+1][j] = V[i].first;
            A[2*i+2][j] = V[i].second;
        }

        cr = min(100, max(cr, 2*s));
    }
}
