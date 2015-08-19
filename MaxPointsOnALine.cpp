/*************************************************************************
	> File Name: MaxPointsOnALine.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月19日 星期日 17时03分07秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

struct Point 
{
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b){}
};

struct Pt 
{
    int dx;
    int dy;
    Pt(): dx(0), dy(0){}
    Pt(int x, int y)
    {
        int g = gcd(abs(x), abs(y));
        if(x == 0 && y == 0) dx = 0, dy = 0;
        else if(x == 0) dx = 0, dy = 1;
        else if(y == 0) dx = 1, dy = 0;
        else if(y > 0) dx = x / g, dy = y / g;
        else if(y < 0) dx = -x / g, dy = -y / g;
    }
    int gcd(int a, int b)
    {
        if(b == 0) return a;
        else return gcd(b, a % b);
    }
    bool operator==(const Pt &b) const 
    {
        return dx == b.dx && dy == b.dy;
    }
    bool operator<(const Pt &b) const
    {
        if(dx == b.dx) return dy < b.dy;
        return dx < b.dx;
    }
};

class Solution 
{
public:
    int maxPoints(vector<Point>& points)
    {
        int size = points.size();
        int result = 0;
        Pt zero(0, 0);
        map<Pt, int> m;
        for(int i = 0; i < size - 1; ++i)
        {
            int ss = 0, sp = 0;
            for(int j = i + 1; j < size; ++j)
            {
                Pt slope(points[i].x - points[j].x, points[i].y - points[j].y);
                if(slope == zero) ++sp;
                else ss = max(ss, ++m[slope]);
            }
            result = max(result, ss + sp);
        }
        return result;
    }

};

int main()
{
    Solution sol;
    Point pts[3] = {
        Point(1, 2), Point(2, 3), Point(1, 3)
    };
    vector<Point> points(pts, pts + sizeof(pts)/sizeof(pts[0]));
    cout<<sol.maxPoints(points)<<endl;

    return 0;
}
