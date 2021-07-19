//
//  BOJ
//  ver.C++
//
//  Created by GGlifer
//
//  Open Source

#include <iostream>
#include <map>

using namespace std;

#define endl '\n'

// Set up : Global Variables
map<char,int> V;

// Set up : Functions Declaration
int decoder(string r);
string encoder(int val);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Process
    V['I'] = 1;
    V['V'] = 5;
    V['X'] = 10;
    V['L'] = 50;
    V['C'] = 100;
    V['D'] = 500;
    V['M'] = 1000;

    // Set up : Input
    string r1, r2;
    cin >> r1 >> r2;

    // Process
    int a1 = decoder(r1);
    int a2 = decoder(r2);

    // Control : Output
    cout << a1+a2 << endl;
    cout << encoder(a1+a2) << endl;
}

// Helper Functions
int decoder(string r)
{
    int val = 0;
    for (int i=0; i<r.length(); i++) {
        val += V[r[i]];
        if (i > 0 && V[r[i-1]] < V[r[i]]) {
            val -= 2*V[r[i-1]];
        }
    }

    return val;
}

string encoder(int val)
{
    string rome;

    int d4 = val / 1000;
    val %= 1000;
    for (int i=0; i<d4; i++) {
        rome.push_back('M');
    }

    int d3 = val / 100;
    val %= 100;
    if (d3 == 4 || d3 == 9) {
        rome.push_back('C');
        if (d3 == 4) { rome.push_back('D'); }
        if (d3 == 9) { rome.push_back('M'); }
    } else {
        if (d3 >= 5) { rome.push_back('D'); d3 -= 5; }
        for (int i=0; i<d3; i++) {
            rome.push_back('C');
        }
    }

    int d2 = val / 10;
    val %= 10;
    if (d2 == 4 || d2 == 9) {
        rome.push_back('X');
        if (d2 == 4) { rome.push_back('L'); }
        if (d2 == 9) { rome.push_back('C'); }
    } else {
        if (d2 >= 5) { rome.push_back('L'); d2 -= 5; }
        for (int i=0; i<d2; i++) {
            rome.push_back('X');
        }
    }

    int d1 = val;
    if (d1 == 4 || d1 == 9) {
        rome.push_back('I');
        if (d1 == 4) { rome.push_back('V'); };
        if (d1 == 9) { rome.push_back('X'); }
    } else {
        if (d1 >= 5) { rome.push_back('V'); d1 -= 5; }
        for (int i=0; i<d1; i++) {
            rome.push_back('I');
        }
    }

    return rome;
}
