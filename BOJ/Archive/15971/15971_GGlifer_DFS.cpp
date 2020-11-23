//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, R1, R2;
struct Node { int no, dist; };
vector<Node> adjList[100000+1];
bool isVisited[100000+1];
struct Result { bool isMet; int sum, maxi; };

// Set up : Functions Declaration
Result dfs(int c, int sum, int maxi);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> R1 >> R2;
    for (int i=0; i<N-1; i++) {
        int r1, r2, dist;
        cin >> r1 >> r2 >> dist;
        adjList[r1].push_back({r2, dist});
        adjList[r2].push_back({r1, dist});
    }

    // Process
    Result res = dfs(R1, 0, 0);
    int ans = res.sum - res.maxi;

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
Result dfs(int c, int sum, int maxi)
{
    isVisited[c] = true;
    if (c == R2) return {true, sum, maxi};

    for (Node node : adjList[c]) {
        int n = node.no;
        int d = node.dist;
        if (not(isVisited[n])) {
            Result res = dfs(n, sum+d, max(maxi, d));
            if (res.isMet) {
                return res;
            }
        }
    }

    return {false, -1, -1,};
}
