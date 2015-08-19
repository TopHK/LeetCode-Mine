/*************************************************************************
	> File Name: LongestValidParentheses.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月07日 星期二 14时29分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
int longestValidParentheses(string s)
{
    int size = s.size();
    if(size < 2) return 0;
    vector<bool> temp(size, false);
    vector<vector<bool> > dp(size+1, temp);
    for(int j=0; j<size; ++j) dp[0][j] = true;
    int maxLen = 0;
    for(int len=0; len<=size; len+=2)
    {
        for(int j=0; j<size; ++j)
        {
            if(j+len<size && dp[len][j])
            {
                if(j>0 && s[j-1]=='(' && s[j+len]==')') 
                {
                    dp[len+2][j-1] = true;
                    maxLen = len+2;
                }
                if(s[j+len]=='(' && s[j+len+1]==')') 
                {
                    dp[len+2][j] = true;
                    maxLen = len+2;
                }
            }
        }
    }
    return maxLen;
}
*/

int longestValidParentheses(string s)
{
    int size = s.size();
    if(size < 2) return 0;   
    vector<int> dp(size, 0);
    int maxLen = 0;
    for(int i=1; i<size; ++i)
    {
        if(s[i] == ')')
        {
            if(s[i-1] == '(') 
            {
                if(i>=2) dp[i] = dp[i-2]+2;
                else dp[i] = 2;
            }
            if(s[i-1] == ')')
            {
                if(dp[i-1] == 0) dp[i] = 0;
                else 
                {
                    if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(') 
                    {
                        dp[i] = dp[i-1]+2;      
                        if(i-dp[i-1]-2 >= 0) dp[i] += dp[i-dp[i-1]-2];
                    }
                }
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main()
{
    string s1(")()())");
    cout<<longestValidParentheses(s1)<<endl;
    string s2("(()");
    cout<<longestValidParentheses(s2)<<endl;
    string s3("((())())");
    cout<<longestValidParentheses(s3)<<endl;

    return 0;
}
