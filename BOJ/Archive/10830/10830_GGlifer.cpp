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
int N;
long B;
typedef vector<vector<int>> Matrix;
map<int,Matrix> dp;
#define MOD 1000

// Set up : Functions Declaration
Matrix pow(long e);
Matrix mul(Matrix U, Matrix V);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> B;
    Matrix A(N, vector<int>(N));
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> A[i][j];

    // Process
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            A[i][j] %= MOD;
        }
    }

    Matrix E(N, vector<int>(N));
    for (int i=0; i<N; i++) {
        E[i][i] = 1;
    }

    dp[0] = E;
    dp[1] = A;

    Matrix ANS = pow(B);

    // Control : Output
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << ANS[i][j] << ' ';
        } cout << endl;
    }
}

// Helper Functions
Matrix pow(long e)
{
    if (e == 0 || e == 1) return dp[e];
    if (dp.find(e) != dp.end()) return dp[e];
    return dp[e] = (e%2) ? mul(pow(e-1), pow(1)) : mul(pow(e/2), pow(e/2));
}

Matrix mul(Matrix U, Matrix V)
{
    Matrix R(N, vector<int>(N, 0));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                R[i][j] += U[i][k] * V[k][j];
            } R[i][j] %= MOD;
        }
    }
    return R;
}
