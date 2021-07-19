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
int N, E;
struct Node { int no, dist; };
struct State { int no, dist; };
vector<Node> A[800+1];
#define INF (800*1000+1)

// Set up : Functions Declaration
bool operator > (State &u, State &v);
int Dijkstra(int s, int e);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> E;
    for (int i=0; i<E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A[a].push_back({b, c});
        A[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;

    // Process
    int tmp1 = Dijkstra(1, v1) + Dijkstra(v1, v2) + Dijkstra(v2, N);
    int tmp2 = Dijkstra(1, v2) + Dijkstra(v2, v1) + Dijkstra(v1, N);
    int ans = min(tmp1, tmp2);

    // Control : Output
    cout << ((ans >= INF) ? -1 : ans) << endl;
}

// Helper Functions
bool operator > (State &u, State &v)
{
    return make_tuple(u.dist, u.no) > make_tuple(v.dist, v.no);
}

int Dijkstra(int s, int e)
{
    int dp[N+1];
    fill(&dp[1], &dp[N+1], INF);
    priority_queue<State,vector<State>,greater<>> pq;

    dp[s] = 0;
    pq.push({s, dp[s]});

    while (not(pq.empty())) {
        auto [c, cd] = pq.top();
        pq.pop();

        if (cd > dp[c]) continue;

        for (auto [n, d] : A[c]) {
            if (dp[n] > dp[c]+d) {
                dp[n] = dp[c]+d;
                pq.push({n, dp[n]});
            }
        }
    }

    return dp[e];
}
