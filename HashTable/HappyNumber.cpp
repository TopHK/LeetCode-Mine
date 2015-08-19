/*************************************************************************
	> File Name: HappyNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月20日 星期六 21时53分25秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int generatorNext(int n)
{
    int result = 0; 
    while(n) 
    {
        int digit = n%10;
        result += digit*digit;
        n /= 10;
    }
    return result;
}

bool isHappy(int n)
{
    map<char, bool> numSequence;
    while(n != 1)
    {
        n = generatorNext(n);
        if(numSequence.find(n) != numSequence.end()) return false;
        else numSequence[n] = true;
    }
    return true;
}

