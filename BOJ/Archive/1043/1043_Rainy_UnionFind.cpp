//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int P[50+1], R[50+1];

// Set up : Functions Declaration
int find(int x);
void merge(int x, int y);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, M;
    cin >> N >> M;
    int K; cin >> K;
    int T[K];
    for (int i=0; i<K; i++)
        cin >> T[i];
    vector<int> PTY[M];
    for (int i=0; i<M; i++) {
        int num; cin >> num;
        for (int j=0; j<num; j++) {
            int no; cin >> no;
            PTY[i].push_back(no);
        }
    }

    // Control : Output
    if (K == 0) {
        cout << M << endl;
        exit(0);
    }

    // Process
    for (int i=1; i<=N; i++) {
        P[i] = i;
        R[i] = 1;
    }

    for (int i=0; i<M; i++) {
        vector<int> pty = PTY[i];
        int size = pty.size();
        if (size > 1) {
            for (int j=1; j<size; j++) {
                if (find(pty[0]) != find(pty[j])) {
                    merge(pty[0], pty[j]);
                }
            }
        }
    }

    set<int> S;
    for (int t : T) {
        S.insert(find(t));
    }

    int ans = 0;
    for (int i=0; i<M; i++) {
        vector<int> pty = PTY[i];
        if (pty.empty()) { ans++; continue; }
        int p = find(pty.front());
        if (S.find(p) == S.end()) {
            ans++;
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
int find(int x)
{
    if (P[x] == x) return x;
    return P[x] = find(P[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);

    if (R[x] < R[y])
        swap(x, y);

    P[y] = x;
    if (R[x] == R[y])
        R[x]++;
}
