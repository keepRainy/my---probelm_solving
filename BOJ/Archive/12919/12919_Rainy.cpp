//
//  BOJ
//  ver.C++
//
//  Created by Rainy
//
//  Open Source

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
string pop(string s);
string turn(string s);
bool isPossible(const string &S, string T);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    string S; cin >> S;
    string T; cin >> T;

    // Process
    // Control : Output
    cout << ((isPossible(S, T)) ? 1 : 0 ) << endl;
}

// Helper Functions
string pop(string s)
{
    s.pop_back();
    return s;
}

string turn(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

bool isPossible(const string &S, string T)
{
    if (S == T)
        return true;

    char f = T.front();
    char b = T.back();

    if (f == 'A' && b == 'A')
        return isPossible(S, pop(T));

    if (f == 'A' && b == 'B')
        return false;

    if (f == 'B' && b == 'A') /* B-->A 꼴이면 */
        return isPossible(S, pop(T)) || isPossible(S, pop(turn(T)));

    if (f == 'B' && b == 'B')
        return isPossible(S, pop(turn(T)));

    return false;
}
