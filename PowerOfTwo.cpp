/*************************************************************************
	> File Name: PowerOfTwo.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月06日 星期一 20时00分57秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if(n == 1) return true;
    if(n==0 || n==INT_MIN) return false;
    if(n&1 == 1) return false;
    int count = 0;
    int bitsNum = 32;
    while(bitsNum--)
    {
        if(n&1 == 1) count++;
        n >>= 1;
        if(count >= 2) return false;
    }
    return count == 1;
}

int main()
{
    int n1 = 32;
    int n2 = 36;
    int n3 = 0;
    int n4 = 79;
    cout<<isPowerOfTwo(n1)<<endl;
    cout<<isPowerOfTwo(n2)<<endl;
    cout<<isPowerOfTwo(n3)<<endl;
    cout<<isPowerOfTwo(n4)<<endl;

    return 0;
}

