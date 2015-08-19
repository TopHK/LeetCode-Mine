/*************************************************************************
	> File Name: palindromePartitioning.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月27日 星期六 19时41分35秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<limits.h>
using namespace std;

/*
class Solution
{
private:
    int count; 
public:
    bool isPalindrome(const string& str)
    {
        int size = str.size();
        for(int i=0; i<(size>>1); ++i)
            if(str[i] != str[size-i-1]) return false;
        return true;
    }
    void partitionCore(string s, int start, vector<string>& oneResult)
    {
        if(start == s.size())
        {
            if(oneResult.size() < count) count = oneResult.size();
            return;
        }
        for(int i=s.size()-1; i>=start; --i)
        {
            string temp = s.substr(start, i-start+1);
            if(isPalindrome(temp))
            {
                vector<string> tempStr(oneResult.begin(), oneResult.end());
                tempStr.push_back(temp);
                partitionCore(s, i+1, tempStr);
            }
        }
    }
    int mincut(string s)
    {
        if(s.empty()) return 0;
        count = INT_MAX;
        vector<string> oneResult;
        partitionCore(s, 0, oneResult);
        return count;
    }
};

void print(const vector<vector<string> >& str)
{
    for(int i=0; i<str.size(); ++i)
    {
        for(int j=0; j<str[i].size(); ++j)
            cout<<str[i][j]<<" ";
        cout<<endl;
    }
}
*/

int minCut(string s)
{
    int size = s.size();
    if(size <= 1) return 0;
    vector<int> count(size, 0);
    vector<vector<int> > dp(size, count);
    count.resize(size+1, 0);
    for(int i=size-1; i>=0; --i)
    {
        count[i] = INT_MAX;
        for(int j=i; j<size; ++j)
        {
            if(s[i]==s[j] && (j-i<2 || dp[i+1][j-1]==1))
            {
                dp[i][j] = 1;
                count[i] = min(1+count[j+1], count[i]);
            }
        }
    }
    return count[0] - 1;
}

int main()
{
    string str("aab");
    cout<<minCut(str)<<endl;

    return 0;
}

