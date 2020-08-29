//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Point { int y, x; };

// Set up : Functions Declaration
long FT(Point from, Point to);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, M, K;
    cin >> N >> M >> K;

    // Process
    int ky = (K == 0) ? 0 : (K-1) / M;
    int kx = (K == 0) ? 0 : (K-1) % M;

    Point s = {0, 0};
    Point m = {ky, kx};
    Point e = {N-1, M-1};

    long s2m = FT(s, m);
    long m2e = FT(m, e);

    // Control : Output
    cout << s2m * m2e << endl;
}

// Helper Functions
long FT(Point from, Point to)
{
    int r = to.y - from.y;
    int c = to.x - from.x;

    long ret = 1;
    for (int i=1; i<=c; i++) {
        ret *= (r+i);
        ret /= i;
    } return ret;
}
