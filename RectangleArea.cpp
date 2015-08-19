/*************************************************************************
	> File Name: RectangleArea.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 19时56分03秒
 ************************************************************************/

#include<iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int maxArea = (C-A)*(D-B) + (G-E)*(H-F);
    int A1 = max(A, E);
    int B1 = max(B, F);
    int C1 = min(C, G);
    int D1 = min(D, H);
    if(A1>=C1 || B1>=D1) return maxArea;
    int intersectionArea = (C1-A1)*(D1-B1);
    return maxArea-intersectionArea;
}
