//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
bool C[14], D[14*2-1], AD[14*2-1];

// Set up : Functions Declaration
int f(int R);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N;

    // Process
    int ans = f(0);

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int f(int R)
{
    if (R == N) return 1;
    int ret = 0;
    for (int i=0; i<N; i++) {
        int y = R;
        int x = i;
        if (!C[x] && !D[N-1-x+y] && !AD[x+y]) {
            C[x] = D[N-1-x+y] = AD[x+y] = true;
            ret += f(R+1);
            C[x] = D[N-1-x+y] = AD[x+y] = false;
        }
    }
    return ret;
}
