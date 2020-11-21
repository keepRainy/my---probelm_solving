//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int K;
int G[13];
int S;
vector<bool> canMeasure;

// Set up : Functions Declaration
void f(int idx, int weight);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> K;
    for (int i=0; i<K; i++) {
        cin >> G[i];
        S += G[i];
    }

    // Process
    canMeasure.resize(S+1, false);
    f(0, 0);

    // Control : Output
    int ans = 0;
    for (int i=1; i<S; i++) {
        if (not(canMeasure[i])) { ans++; }
    } cout << ans << endl;
}

// Helper Functions
void f(int idx, int weight)
{
    if (idx == K) {
        if (weight > 0) {
            canMeasure[weight] = true;
        } return;
    }

    f(idx+1, weight);
    f(idx+1, weight+G[idx]);
    f(idx+1, weight-G[idx]);
}
