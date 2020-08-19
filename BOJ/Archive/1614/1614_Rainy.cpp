//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>

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
    int f; cin >> f;
    long cnt; cin >> cnt;

    // Process
    long ans;
    switch (f) {
        case 1: /* 엄지 */
            ans = cnt/1 * 8;
            ans += 0;
            break;

        case 2: /* 검지 */
            ans = cnt/2 * 8;
            (cnt % 2) ? ans += 7 : ans += 1;
            break;

        case 3: /* 중지 */
            ans = cnt/2 * 8;
            (cnt % 2) ? ans += 6 : ans += 2;
            break;

        case 4: /* 약지 */
            ans = cnt/2 * 8;
            (cnt % 2) ? ans += 5 : ans += 3;
            break;

        case 5: /* 새끼 */
            ans = cnt/1 * 8;
            ans += 4;
            break;

        default: throw;
    }

    // Control : Output
    cout << ans << endl;
}

// Helper Functions
/* None */

