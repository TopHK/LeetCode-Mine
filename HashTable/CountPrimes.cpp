/*************************************************************************
	> File Name: CountPrimes.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月20日 星期六 22时07分54秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<memory.h>
#include<algorithm>
using namespace std;

bool isPrime(int n)
{
    for(int i=2; i<=(int)sqrt(n); ++i) 
        if(n%i == 0) return false;
    return true;
}

int countPrimes(int n)
{
    if(n == 1) return 0;
    if(n == 0) return 0;   
    int count = 1;
    for(int i=3; i<n; i+=2)
        if(isPrime(i)) count++;
    return count;
}

int countPrimes2(int n)
{
    if(n == 1) return 0;
    bool* isPrime = new bool[n];
    fill(isPrime, isPrime+n, true);
    for(int i=2; i<n; ++i)
    {
        if(!isPrime[i]) continue;
        for(long long j=(long long)i*(long long)i; j<n; j+=i) 
            isPrime[j] = false;
    }
    int count = 0;
    for(int i=2; i<n; ++i) 
        if(isPrime[i]) count++;
    return count;
}

int main()
{
    int n = 499979;
    int n2 = 4434899;
//    cout<<countPrimes(n2)<<endl;
    cout<<countPrimes2(n2)<<endl;
    return 0;
}

