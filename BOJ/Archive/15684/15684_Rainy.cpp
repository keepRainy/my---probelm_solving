//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M, H;
bool isBridge[30+1][10+1];

// Set up : Functions Declaration
int arrive(int no);
bool isOk();
bool f(int cnt);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M >> H;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        isBridge[a][b] = true;
    }

    // Process
    // Control : Output
    for (int i=0; i<=3; i++) {
        if (f(i)) {
            cout << i << endl;
            exit(0);
        }
    }
    cout << -1 << endl;
}

// Helper Functions
int arrive(int no)
{
    for (int i=1; i<=H; i++) {
        if (isBridge[i][no]) {
            no++;
        } else if (isBridge[i][no-1]) {
            no--;
        }
    } return no;
}

bool isOk()
{
    for (int i=1; i<=N; i++) {
        if (i != arrive(i)) return false;
    } return true;
}

bool f(int cnt)
{
    if (cnt == 0) {
        return isOk();
    }

    for (int j=1; j<=N-1; j++) {
        for (int i=1; i<=H; i++) {
            if (isBridge[i][j-1] || isBridge[i][j] || isBridge[i][j+1]) continue;

            isBridge[i][j] = true;
            if (f(cnt-1)) return true;
            isBridge[i][j] = false;

            while (not(isBridge[i][j-1]) && not(isBridge[i][j+1])) i++;
        }
    }

    return false;
}
