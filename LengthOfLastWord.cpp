/*************************************************************************
	> File Name: LengthOfLastWord.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 15时29分57秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int lengthOfLastWord(string s)
{
    if(s.empty()) return 0;
    int size = s.size();
    int lengthOfWord = 0;
    bool foundAlphabet = false;

    for(int i=size-1; i>=0; i--)
    {
        char ch = s[i];
        if(ch == ' ')
        {
            if(!foundAlphabet) continue;
            else break;
        }
        else
        {
            if(!foundAlphabet) foundAlphabet = true;
            lengthOfWord++;
        }
    }
    return lengthOfWord;
}

int main()
{
    string str = " hello World  ";
    cout<<lengthOfLastWord(str)<<endl;

    return 0;
}

