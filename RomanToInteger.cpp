/*************************************************************************
	> File Name: RomanToInteger.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 20时40分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int romanToInt(string s)
{
    char basicCharacter[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    int basicInteger[7] = {1, 5, 10, 50, 100, 500, 1000};
    map<char, int> RomanToInteger;
    for(int i=0; i<7; ++i) 
        RomanToInteger[basicCharacter[i]] = basicInteger[i];

    int size = s.size();
    int previous = RomanToInteger[s[0]];
    int result = previous;
    for(int i=1; i<size; ++i)
    {
        int current = RomanToInteger[s[i]];
        if(current <= previous)
            result += current;
        else result = result+current-2*previous;
        previous = current;
    }
    return result;
}

int main()
{
    string str1 = "MCMXC";
    string str2 = "MMMCMXCIX";

    cout<<str1<<":"<<romanToInt(str1)<<endl;
    cout<<str2<<":"<<romanToInt(str2)<<endl;

    return 0;
}
