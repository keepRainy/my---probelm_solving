//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <deque>
#include <sstream>
#include <algorithm>

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
    int T; cin >> T;

    while (T--) {
        string P; cin >> P;
        int N; cin >> N;
        string X; cin >> X;

        // Process
        X = X.substr(1, X.length()-2);
        stringstream ss(X);
        string buffer;
        deque<string> nums;
        while (getline(ss, buffer, ',')) {
            nums.push_back(buffer);
        } bool isReversed = false;

        bool isError = false;
        for (char cmd : P) {
            if (isError) break;
            switch (cmd) {
                case 'R':
                    isReversed ^= true;
                    break;

                case 'D':
                    if (nums.empty()) {
                        isError = true;
                        break;
                    } else {
                        (isReversed) ? nums.pop_back() : nums.pop_front();
                    } break;

                default: throw;
            }
        }

        // Control : Output
        if (isError) {
            cout << "error" << endl;
        } else {
            if (isReversed) {
                reverse(nums.begin(), nums.end());
            } string ans;
            ans.push_back('[');
            if (not(nums.empty())) {
                for (string &num : nums) {
                    ans += num;
                    ans += ",";
                }  ans.pop_back();
            } ans.push_back(']');
            cout << ans << endl;
        }
    }
}

// Helper Functions
/* None */

