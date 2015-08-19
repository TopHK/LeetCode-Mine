/*************************************************************************
	> File Name: ReverseInteger.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 08时42分48秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

int reverse(int x)
{
    int flag = 1;
    long long y = (long long)x;
    if(y < 0)
    {
        flag = -1;
        y *= -1;
    }
    if(0 == y) return 0;
    long long result = 0;
    while(y%10 == 0) y/=10;
    while(y)
    {
        int digit = y%10;
        result = result*10+digit;
        if(result > INT_MAX) return 0;
        y /= 10;
    }
    result *= flag;
    return (int)result;
}

int main()
{
    int num1 = 123;
    int num2 = -123;
    int num3 = 1230000;
    int num4 = INT_MIN;
    int num5 = INT_MAX;
    int num6 = 0;

    cout<<num1<<":"<<reverse(num1)<<endl;
    cout<<num2<<":"<<reverse(num2)<<endl;
    cout<<num3<<":"<<reverse(num3)<<endl;
    cout<<num4<<":"<<reverse(num4)<<endl;
    cout<<num5<<":"<<reverse(num5)<<endl;
    cout<<num6<<":"<<reverse(num6)<<endl;

    return 0;
}

