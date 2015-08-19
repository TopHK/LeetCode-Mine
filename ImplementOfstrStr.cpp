/*************************************************************************
	> File Name: ImplementOfstrStr.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 09时37分59秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle)
{
    if(needle.empty()) return 0;
    else if(haystack.empty()) return -1;
    if(haystack.size() < needle.size()) return -1;
    int sizeOfHay = haystack.size();
    int sizeOfNeedle = needle.size();

    for(int i=0; i<=sizeOfHay-sizeOfNeedle; ++i)
    {
        string temp = haystack.substr(i, sizeOfNeedle);
        if(temp == needle) return i;
    }
    return -1;
}

int main()
{
    string haystack = "abcourageksd";
    string needle = "couragek";
    string needle2 = "sd";
    cout<<strStr(haystack, needle2)<<endl;
    return 0;
}

