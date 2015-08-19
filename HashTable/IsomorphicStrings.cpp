/*************************************************************************
	> File Name: IsomorphicStrings.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月20日 星期六 21时29分33秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;a

bool isIsomorphic(string s, string t)
{
    map<char, char> strToStr;
    for(int i=0; i<s.size(); ++i)
    {
        if(strToStr.find(s[i]) == strToStr.end()) 
            strToStr[s[i]] = t[i];
        else if(strToStr[s[i]] != t[i]) 
            return false;
    }
    return true;
}

