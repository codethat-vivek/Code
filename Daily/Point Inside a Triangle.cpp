/*
Question - 
  You will be given the coordinates of four points A, B, C and X.
  You have to find whether the Point X lies inside the triangle formed by the points A, B and C or not.
  For Example: 
    [format of input -> x and y coordinate of a, b, c, x]
    Input:
    0 0 10 0 0 10 2 2
    Output: 
    1
*/

// SOLUTION - 

#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
        int x, y;
};

float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
} 

int main()
{
    Point p, q, r, s;
    cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y >> s.x >> s.y;
    float bigArea = area(p.x, p.y, q.x, q.y, r.x, r.y);
    float area1 = area(p.x, p.y, q.x, q.y, s.x, s.y);
    float area2 = area(p.x, p.y, r.x, r.y, s.x, s.y);
    float area3 = area(q.x, q.y, r.x, r.y, s.x, s.y);
    if(area1 + area2 + area3 == bigArea)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
