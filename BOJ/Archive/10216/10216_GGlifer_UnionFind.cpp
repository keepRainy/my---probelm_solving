//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N;
struct Camp { int x, y, r; };
Camp C[3000];
int P[3000];
int R[3000];

// Set up : Functions Declaration
bool isConnected(int u, int v);
int find(int u);
void merge(int u, int v);

int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            C[i] = {x, y, r};
        }

        // Process
        for (int i=0; i<N; i++) {
            P[i] = i;
            R[i] = 1;
        }

        int ans = N;
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (find(i) != find(j)) {
                    if (isConnected(i, j)) {
                        merge(i, j);
                        ans--;
                    }
                }
            }
        }

        // Control : Output
        cout << ans << endl;
    }
}

// Helper Functions
bool isConnected(int u, int v)
{
    Camp cu = C[u];
    Camp cv = C[v];
    int dy = cv.y - cu.y;
    int dx = cv.x - cu.x;
    int ru = cu.r;
    int rv = cv.r;
    return dy*dy + dx*dx <= (ru+rv)*(ru+rv);
}

int find(int u)
{
    if (P[u] == u) return u;
    return P[u] = find(P[u]);
}

void merge(int u, int v)
{
    int pu = find(u);
    int pv = find(v);

    if (R[pu] < R[pv]) {
        swap(pu, pv);
    }

    P[pv] = pu;
    if (R[pu] == R[pv]) {
        R[pu]++;
    }
}
