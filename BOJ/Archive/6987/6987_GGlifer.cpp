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
enum Team { A, B, C, D, E, F };
enum Side { L, R };
enum Status { WIN, DRAW, LOSE };
int P[15][2] = {
        {A, B}, {A, C}, {A, D}, {A, E}, {A, F},
        {B, C}, {B, D}, {B, E}, {B, F},
        {C, D}, {C, E}, {C, F},
        {D, E}, {D, F},
        {E, F}
};
// int call = 0;

// Set up : Functions Declaration
bool isVarsValid(vector<vector<int>> &score);
bool isLogicallyValid(int cnt, vector<vector<int>> &score);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    for (int i=0; i<4; i++) {
        vector<vector<int>> score(6, vector<int>(3, 0));
        for (int j=0; j<6; j++) {
            for (int k=0; k<3; k++) {
                cin >> score[j][k];
            }
        }

        // Process
        bool valid = isVarsValid(score) && isLogicallyValid(0, score);

        // Control : Output
        cout << ((valid) ? 1 : 0) << ' ';
        // cout << call << endl;
    }
}

// Helper Functions
bool isVarsValid(vector<vector<int>> &score)
{
    int sum = 0;
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            if (score[i][j] < 0 || score[i][j] > 6) return false;
            sum += score[i][j];
        }
    }
    return sum == 30;
}

bool isLogicallyValid(int cnt, vector<vector<int>> &score)
{
    // call++;
    if (cnt == 15) return true;

    int tl = P[cnt][L];
    int tr = P[cnt][R];

    if (score[tl][WIN] > 0 && score[tr][LOSE] > 0) {
        score[tl][WIN]--; score[tr][LOSE]--;
        if (isLogicallyValid(cnt+1, score)) return true;
        score[tl][WIN]++; score[tr][LOSE]++;
    }

    if (score[tl][DRAW] > 0 && score[tr][DRAW] > 0) {
        score[tl][DRAW]--; score[tr][DRAW]--;
        if (isLogicallyValid(cnt+1, score)) return true;
        score[tl][DRAW]++; score[tr][DRAW]++;
    }

    if (score[tl][LOSE] > 0 && score[tr][WIN] > 0) {
        score[tl][LOSE]--; score[tr][WIN]--;
        if (isLogicallyValid(cnt+1, score)) return true;
        score[tl][LOSE]++; score[tr][WIN]++;
    }

    return false;
}

