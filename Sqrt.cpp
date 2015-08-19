/*************************************************************************
	> File Name: Sqrt.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月30日 星期二 21时43分20秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

int mySqrt(int x)
{
    if(x <= 1) return x;
    long long squareNum;
    int left = 1;
    int right = (x>>1);
    int middle;
    while(left <= right)
    {
        middle = left+((right-left)>>1);
        squareNum = (long long)middle*(long long)middle;
        if(squareNum>INT_MAX || squareNum>x) right = middle-1;
        else if(squareNum < x) left = middle+1;
        else return middle;
    }
    return (squareNum<x ? middle : middle-1);
}

int main()
{
    int x = 1;
    cout<<mySqrt(x)<<endl;
    x = 2;
    cout<<mySqrt(x)<<endl;
    x = 3;
    cout<<mySqrt(x)<<endl;
    x = 4;
    cout<<mySqrt(x)<<endl;
    x = 256;
    cout<<mySqrt(x)<<endl;
    x = INT_MAX;
    cout<<mySqrt(x)<<endl;

    return 0;
}
