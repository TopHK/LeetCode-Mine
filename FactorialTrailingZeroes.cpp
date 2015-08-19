/*************************************************************************
	> File Name: FactorialTrailingZeroes.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月25日 星期四 16时15分20秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

int trailingZeroes(int n)
{
    if(n < 5) return 0;
    else 
    {
        long long base = 5;
        int numberOfFive = 0;
        while(n>=base && base<INT_MAX)
        {
            numberOfFive += n/base;
            base *= 5;
        }
        return numberOfFive;
    }
}

