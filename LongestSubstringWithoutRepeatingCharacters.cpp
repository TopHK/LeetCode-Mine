/*************************************************************************
	> File Name: LongestSubstringWithoutRepeatingCharacters.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月06日 星期一 19时27分31秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if(s.empty()) return 0;
    int size = s.size();
    if(size == 1) return 1;
    int maxLen = 1;
    int tailIndex = 0;

    int tempLen = 1;
    for(int i=1; i<size; ++i)
    {
        string tempStr = s.substr(tailIndex-tempLen+1, tempLen);
        size_t pos = tempStr.find(s[i]);
        if(pos != string::npos)
            tempLen = tempStr.size()-pos;
        else tempLen += 1;
        tailIndex = i;
        if(tempLen > maxLen)
            maxLen = tempLen;
    }
    return maxLen;
}

int main()
{
    string s1("dvdf");
    string s2("bbbbb");
    string s3("jbpnbwwd");
//    cout<<lengthOfLongestSubstring(s1)<<endl;
    cout<<lengthOfLongestSubstring(s3)<<endl;
    return 0;
}
