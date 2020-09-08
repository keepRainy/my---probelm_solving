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
struct Point { long x, y; };
struct Square { Point ll, lr, ul, ur; };

// Set up : Functions Declaration
bool operator == (const Point &u, const Point &v);
bool isNull(Square s1, Square s2);
bool isPoint(Square s1, Square s2);
bool isLine(Square s1, Square s2);


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int x1, y1, x2, y2;
    Square s1{}, s2{};
    cin >> x1 >> y1 >> x2 >> y2;
    s1.ll.x = s1.ul.x = x1;
    s1.lr.x = s1.ur.x = x2;
    s1.ll.y = s1.lr.y = y1;
    s1.ul.y = s1.ur.y = y2;
    cin >> x1 >> y1 >> x2 >> y2;
    s2.ll.x = s2.ul.x = x1;
    s2.lr.x = s2.ur.x = x2;
    s2.ll.y = s2.lr.y = y1;
    s2.ul.y = s2.ur.y = y2;

    // Process
    // Control : Output
    if (isNull(s1, s2))
        cout << "NULL" << endl;
    else if (isPoint(s1, s2))
        cout << "POINT" << endl;
    else if (isLine(s1, s2))
        cout << "LINE" << endl;
    else
        cout << "FACE" << endl;
}

// Helper Functions
bool operator == (const Point &u, const Point &v)
{
    return u.x == v.x && u.y == v.y;
}

bool isNull(Square s1, Square s2)
{
    if (s1.ll.y > s2.ur.y || s2.ll.y > s1.ur.y) return true;
    if (s1.ll.x > s2.ur.x || s2.ll.x > s1.ur.x) return true;
    return false;
}

bool isPoint(Square s1, Square s2)
{
    if (s1.ll == s2.ur || s2.ll == s1.ur) return true;
    if (s1.lr == s2.ul || s2.lr == s1.ul) return true;
    return false;
}

bool isLine(Square s1, Square s2)
{
    if (s1.ll.x == s2.ur.x || s2.ll.x == s1.ur.x) return true;
    if (s1.ll.y == s2.ur.y || s2.ll.y == s1.ur.y) return true;
    return false;
}

