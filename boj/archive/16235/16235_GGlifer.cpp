//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
int N, M, K;
int A[10][10];
int R[10][10];
int P[10][10];
deque<int> T[10][10];
int dy[8] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dx[8] = {-1, 0, +1, -1, +1, -1, 0, +1};

// Set up : Functions Declaration
void spring_summer();
void autumn_winter();
bool isValid(int y, int x);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    cin >> N >> M >> K;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> A[i][j];
    for (int i=0; i<M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        T[--x][--y].push_back(z);
    }

    // Process
    fill(&R[0][0], &R[9][9+1], 5);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            sort(T[i][j].begin(), T[i][j].end());
        }
    }

    while (K--) {
        spring_summer();
        autumn_winter();
    }

    int ans = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            ans += T[i][j].size();
        }
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
void spring_summer()
{
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int s = T[i][j].size();
            bool isDried = false;
            for (int k=0; k<s; k++) {
                int age = T[i][j].front();
                T[i][j].pop_front();
                if (isDried || R[i][j] < age) {
                    isDried = true;
                    R[i][j] += age/2;
                } else {
                    R[i][j] -= age;
                    T[i][j].push_back(age+1);
                    if ((age+1)%5 == 0) {
                        P[i][j]++;
                    }
                }
            }
        }
    }
}

void autumn_winter()
{
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (P[i][j] > 0) {
                for (int k=0; k<8; k++) {
                    int ay = i + dy[k];
                    int ax = j + dx[k];
                    if (isValid(ay, ax)) {
                        T[ay][ax].insert(T[ay][ax].begin(), P[i][j], 1);
                    }
                }
            }
            P[i][j] = 0;
            R[i][j] += A[i][j];
        }
    }
}

bool isValid(int y, int x)
{
    return y >= 0 && y < N && x >= 0 && x < N;
}

