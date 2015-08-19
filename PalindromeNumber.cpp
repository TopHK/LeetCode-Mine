/*************************************************************************
	> File Name: PalindromeNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 09时25分02秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

int digitsCount(int x)
{
    int count = 0;
    while(x)
    {
        x /= 10;
        count++;
    }
    return count;
}

bool isPalindrome(int x)
{
    if(x == INT_MIN) return false;
    if(x < 0) x *= -1;
    
    int count = digitsCount(x);
    if(1 == count) return true;
    int upperBase = 1;
    for(int i=1; i<count; ++i) upperBase *= 10;

    while(x >= 10)
    {
        int leftDigit = x/upperBase;
        int rightDigit = x%10;
        if(leftDigit != rightDigit) return false;
        x -= leftDigit*upperBase;
        x /= 10;
        upperBase /= 100;
    }
    return true;
}

bool isPalindrome2(int x)
{
    if(x<0) return false;
    long long y = (long long)x;
    long long result = 0;
    while(y)
    {
        int digit = y%10;
        result = result*10+digit;
        y /= 10;
    }
    return (result == x);
}

int main()
{
    int num1 = 0;
    int num2 = 121;
    int num3 = -121;
    int num4 = 12300;
    int num5 = 5867;
    int num6 = INT_MAX;
    int num7 = INT_MIN;

    cout<<num1<<":"<<isPalindrome2(num1)<<endl;
    cout<<num2<<":"<<isPalindrome2(num2)<<endl;
    cout<<num3<<":"<<isPalindrome2(num3)<<endl;
    cout<<num4<<":"<<isPalindrome2(num4)<<endl;
    cout<<num5<<":"<<isPalindrome2(num5)<<endl;
    cout<<num6<<":"<<isPalindrome2(num6)<<endl;
    cout<<num7<<":"<<isPalindrome2(num7)<<endl;

    return 0;
}
