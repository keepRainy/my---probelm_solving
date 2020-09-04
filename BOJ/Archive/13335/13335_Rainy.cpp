//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

#define endl '\n'

// Set up : Global Variables
struct Truck { int w, d; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N, W, L;
    cin >> N >> W >> L;
    queue<Truck> waiting;
    for (int i=0; i<N; i++) {
        int w; cin >> w;
        waiting.push({w, 0});
    }

    // Process
    deque<Truck> bridge;
    int bw = 0;

    int time = 0;
    while (not(waiting.empty() && bridge.empty())) {
        time++;

        if (not(bridge.empty())) {
            Truck t = bridge.front();
            if (t.d == W) {
                bridge.pop_front();
                bw -= t.w;
            }
        }

        if (not(waiting.empty())) {
            Truck t = waiting.front();
            if (bw + t.w <= L) {
                bridge.push_back(t);
                waiting.pop();
                bw += t.w;
            }
        }

        for (Truck &t : bridge) {
            t.d++;
        }
    }

    // Control : Output
    cout << time << endl;
}

// Helper Functions
/* None */

