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
struct Point { int y, x; };

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int T; cin >> T;

    while (T--) {
        int M, N;
        cin >> M >> N;

        // Process
        vector<Point> P;
        if (M%2 == 0) {
            for (int i=0; i<M; i+=2) {
                for (int j=0; j<N; j++)
                    P.push_back({i, j});
                for (int j=N-1; j>=0; j--)
                    P.push_back({i+1, j});
            }
        } else if (N%2 == 0) {
            for (int j=0; j<N; j+=2) {
                for (int i=0; i<M; i++)
                    P.push_back({i, j});
                for (int i=M-1; i>=0; i--)
                    P.push_back({i, j+1});
            }
        } else {
            for (int i=0; i<M-1; i+=2) {
                for (int j=0; j<N-1; j++)
                    P.push_back({i, j});
                for (int j=N-2; j>=0; j--)
                    P.push_back({i+1, j});
            } for (int j=0; j<N-1; j++) {
                P.push_back({M-1, j});
            } for (int i=M-1; i>=0; i--) {
                P.push_back({i, N-1});
            }
        }

        // Control : Output
        cout << 1 << endl;
        for (Point p : P) {
            cout << "(" << p.y << "," << p.x << ")" << endl;
        }
    }
}

// Helper Functions
/* None */

