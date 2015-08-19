/*************************************************************************
	> File Name: Shortestpalindrome.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月17日 星期五 10时59分51秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string shortestPalindrome2(string s)
{
    int size = s.size();
    if(size < 2) return s;
    int middle = size >> 1;
    int leftLen = 0, rightLen = 0;
    string sCopy(s);
    reverse(sCopy.begin(), sCopy.end());
    if(s == sCopy) return s;
    string leftPart, rightPart;
    while(middle >= 0)
    {
        leftLen = middle;
        rightLen = size - middle -1;
        leftPart = s.substr(0, leftLen);
        if(rightLen >= leftLen)
        {
            rightPart = s.substr(middle + 1);
            reverse(rightPart.begin(), rightPart.end());
            if(leftPart.empty() || rightPart.substr(rightLen - leftLen) == leftPart)
                return rightPart + s.substr(middle);
        }
        rightLen = size - middle;
        rightPart = s.substr(middle);
        reverse(rightPart.begin(), rightPart.end());
        if(rightPart.substr(rightLen - leftLen) == leftPart) 
            return rightPart + s.substr(middle);
        middle--;
    }
}

/*
bool isPalindrome(const string& s, int end)
{
    for(int i = 0, j = end; i < j; ++i, --j)
    {
        if(s[i] != s[j]) return false;
    }
    return true;
}

string shortestPalindrome(string s)
{
    int size = s.size();
    if(size < 2) return s;
    for(int end = size-1; end >= 0; --end)    
    {
        if(isPalindrome(s, end))
        {
            if(end == size-1) return s;
            string temp(s.substr(end + 1));
            reverse(temp.begin(), temp.end());
            return temp + s;
        }
    }
}
*/

// KMP Solution 
string shortestPalindrome(string s)
{
    int size = s.size();
    if(size < 2) return s;
    string sCopy(s);
    reverse(sCopy.begin(), sCopy.end());
    string str(s + "#" + sCopy);
    vector<int> nums(str.size(), 0);
    for(int i = 1; i < nums.size(); ++i)
    {
        int j = nums[i-1];
        while(j > 0 && str[i] != str[j])
            j = nums[j-1];
        nums[i] = (j + (str[i] == str[j]));
    }
    return sCopy.substr(0, sCopy.size() - nums[nums.size() - 1]) + s;
}

int main()
{
    string s("abbacd");
    cout<<shortestPalindrome(s)<<endl;

    return 0;
}
