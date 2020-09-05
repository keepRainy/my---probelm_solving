//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <deque>

using namespace std;

#define endl '\n'

// Set up : Global Variables
deque<char> W[4];
bool isVisited[4];

// Set up : Functions Declaration
void rotate(int no, int dir);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    for (int i=0; i<4; i++) {
        W[i].resize(8);
        for (int j=0; j<8; j++) {
            cin >> W[i][j];
        }
    }

    // Process
    int K; cin >> K;
    for (int i=0; i<K; i++) {
        int no, dir;
        cin >> no >> dir;
        rotate(no-1, dir);
    }

    // Control : Output
    int ans = 0;
    for (int i=0; i<4; i++) {
        if (W[i][0] == '1') {
            ans += (1<<i);
        }
    } cout << ans << endl;
}

// Helper Functions
void rotate(int no, int dir)
{
    isVisited[no] = true;

    if (no-1 >= 0 && not(isVisited[no-1])) {
        if (W[no][6] != W[no-1][2]) {
            rotate(no-1, -dir);
        }
    }

    if (no+1 < 4 && not(isVisited[no+1])) {
        if (W[no][2] != W[no+1][6]) {
            rotate(no+1, -dir);
        }
    }

    if (dir == 1) {
        W[no].push_front(W[no].back());
        W[no].pop_back();
    }

    if (dir == -1) {
        W[no].push_back(W[no].front());
        W[no].pop_front();
    }

    isVisited[no] = false;
}
