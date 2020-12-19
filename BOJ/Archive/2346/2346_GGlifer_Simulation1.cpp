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
struct Balloon { int no, num; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    vector<Balloon> B(N);
    for (int i=0; i<N; i++) {
        cin >> B[i].num;
        B[i].no = i+1;
    }

    // Process
    int idx = 0;
    vector<int> A;
    while (true) {
        int num = B[idx].num;
        A.push_back(B[idx].no);
        B.erase(B.begin()+idx);
        if (B.empty()) break;

        int s = B.size();
        if (num > 0) num--;
        idx += num;
        idx %= s;
        if (idx < 0) idx += s;
    }

    // Control : Output
    for (int no : A) {
        cout << no << ' ';
    }
}

// Helper Functions
/* None */

