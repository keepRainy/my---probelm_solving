//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Frame { int no, ord, likes; };

// Set up : Functions Declaration
bool operator < (Frame u, Frame v);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int M; cin >> M;
    int R[M];
    for (int i=0; i<M; i++)
        cin >> R[i];

    // Process
    vector<Frame> F;
    for (int i=0; i<M; i++) {
        int no = R[i];
        auto p = find_if(F.begin(), F.end(), [no](Frame f) {
            return f.no == no;
        });
        if (p != F.end()) {
            p->likes++;
        } else {
            if (F.size() == N) {
                F.erase(min_element(F.begin(), F.end()));
            }
            F.push_back({no, i, 1});
        }
    }

    sort(F.begin(), F.end(),
         [](Frame u, Frame v) {
        return u.no < v.no;
    });

    // Control : Output
    for (Frame f : F) {
        cout << f.no << ' ';
    }
}

// Helper Functions
bool operator < (Frame u, Frame v)
{
    return make_pair(u.likes, u.ord) < make_pair(v.likes, v.ord);
}
