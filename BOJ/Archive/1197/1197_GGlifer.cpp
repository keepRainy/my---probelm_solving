//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Edge { int a, b, c; };
int P[10000+1], R[10000+1];

// Set up : Functions Declaration
int find(int x);
void merge(int x, int y);
bool operator > (Edge u, Edge v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int V, E;
    cin >> V >> E;
    priority_queue<Edge, vector<Edge>, greater<>> pq;
    for (int i=0; i<E; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        pq.push({A, B, C});
    }

    // Process
    for (int i=1; i<=V; i++) {
        P[i] = i;
        R[i] = 1;
    }

    int cnt = 0, ans = 0;
    while (cnt < V-1) {
        auto [A, B, C] = pq.top();
        pq.pop();

        if (find(A) == find(B)) continue;
        merge(A, B);
        ans += C;
        cnt++;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
bool operator > (Edge u, Edge v)
{
    return make_tuple(u.c, u.b, u.a) > make_tuple(v.c, v.b, v.a);
}

int find(int x)
{
    if (P[x] == x) return x;
    return P[x] = find(P[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (R[x] < R[y]) swap(x, y);
    P[y] = x;
    if (R[x] == R[y]) R[x]++;
}
