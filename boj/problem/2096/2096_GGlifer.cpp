//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <cstring>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int dpMax[3], dpMin[3];
    for (int i=0; i<3; i++) {
        int n; cin >> n;
        dpMax[i] = dpMin[i] = n;
    }
    for (int i=1; i<N; i++) {
        int A[3];
        for (int j=0; j<3; j++)
            cin >> A[j];

        // Process
        int tmpMax[3], tmpMin[3];
        tmpMax[0] = A[0] + max(dpMax[0], dpMax[1]);
        tmpMax[1] = A[1] + max({dpMax[0], dpMax[1], dpMax[2]});
        tmpMax[2] = A[2] + max(dpMax[1], dpMax[2]);
        
        tmpMin[0] = A[0] + min(dpMin[0], dpMin[1]);
        tmpMin[1] = A[1] + min({dpMin[0], dpMin[1], dpMin[2]});
        tmpMin[2] = A[2] + min(dpMin[1], dpMin[2]);

        memcpy(dpMax, tmpMax, sizeof(tmpMax));
        memcpy(dpMin, tmpMin, sizeof(tmpMin));
    }

    // Control : Output
    cout << max({dpMax[0], dpMax[1], dpMax[2]});
    cout << ' ';
    cout << min({dpMin[0], dpMin[1], dpMin[2]});
}

// Helper Functions
/* None */

