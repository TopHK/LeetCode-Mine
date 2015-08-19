/*************************************************************************
	> File Name: ReverseWordsInAString.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月07日 星期二 11时19分58秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void reverseWords(string& s)
{
    if(s.empty()) return;
    reverse(s.begin(), s.end());
    string::iterator start = s.begin();
    string::iterator last = s.begin();
    while(start != s.end())
    {
        if(*start == ' ')
        {
            start++;
            last++;
        }
        else 
        {
            last++;
            if(last==s.end() || *last==' ') 
            {
                reverse(start, last);
                start = last;
            }
        }
    }
    start = s.begin();
    while(start!=s.end() && *start==' ') s.erase(start);
    last = start;
    while(start != s.end())
    {
        if(*start != ' ')
        {
            start++;
            last++;
        }
        else 
        {
            last++;
            while(last!=s.end() && *last==' ') s.erase(last);
            if(last == s.end())
            {
                s.erase(start);
                return;
            }
            start = last;
        }
    }
}

int main()
{
    string str(" I love    Hejing  ");
    reverseWords(str);
    cout<<str<<endl;

    return 0;
}
