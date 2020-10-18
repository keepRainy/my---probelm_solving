//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int C, P;
vector<int> G;

// Set up : Functions Declaration
int cases(vector<int> pattern);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> C >> P;
    G.resize(C);
    for (int i=0; i<C; i++)
        cin >> G[i];

    // Process
    int ans = 0;
    switch (P) {
        case 1:
            ans += cases({0});
            ans += cases({0, 0, 0, 0});
            break;

        case 2:
            ans += cases({0, 0});
            break;

        case 3:
            ans += cases({0, 0, 1});
            ans += cases({1, 0});
            break;

        case 4:
            ans += cases({1, 0, 0});
            ans += cases({0, 1});
            break;

        case 5:
            ans += cases({0, 0, 0});
            ans += cases({1, 0});
            ans += cases({0, 1});
            ans += cases({1, 0, 1});
            break;

        case 6:
            ans += cases({0, 0, 0});
            ans += cases({0, 0});
            ans += cases({0, 1, 1});
            ans += cases({2, 0});
            break;

        case 7:
            ans += cases({0, 0, 0});
            ans += cases({0, 0});
            ans += cases({1, 1, 0});
            ans += cases({0, 2});
            break;

        default: throw;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int cases(vector<int> pattern)
{
    int cnt = 0;
    int L = pattern.size();
    for (int i=0; i<=C-L; i++) {
        vector<int> sub(G.begin()+i, G.begin()+i+L);
        int h = sub[0] - pattern[0];
        if (h < 0) continue;
        bool isValid = true;
        for (int j=1; j<L; j++) {
            if (h != sub[j] - pattern[j]) {
                isValid = false;
                break;
            }
        }
        if (isValid) { cnt++; }
    }
    return cnt;
}

