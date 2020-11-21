//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <algorithm>
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
    string words[N];
    for (int i=0; i<N; i++) {
        cin >> words[i];
    }

    // Process
    map<char,int> coeff;
    for (int i=0; i<N; i++) {
        int offset = 1;
        reverse(words[i].begin(), words[i].end());
        for (char c : words[i]) {
            coeff[c] += offset;
            offset *= 10;
        }
    }

    vector<int> weight;
    for (auto [letter, coeff] : coeff) {
        weight.push_back(coeff);
    } sort(weight.begin(), weight.end(), greater<>());

    int ans = 0;
    for (int i=0; i<weight.size(); i++) {
        ans += weight[i] * (9-i);
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */
