/*************************************************************************
	> File Name: InterleavingString.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月15日 星期三 09时15分22秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    if(s1.empty()) return s2 == s3;
    else if(s2.empty()) return s1 == s3;
    int size1 = s1.size();
    int size2 = s2.size();
    int size = size1 + size2;
    if(s3.size() != size) return false;
    vector<bool> temp(size1+1, false);
    vector<vector<bool> > dp(size+1, temp);
    for(int j=0; j<size1+1; ++j) dp[0][j] = true;

    for(int m=1; m<=size; ++m)
    {
        for(int n=0; n<=m && n<=size1; ++n)
        {
            if(n == 0) dp[m][n] = (dp[m-1][n] && s3[m-1] == s2[m-1]);
            else 
            {
                bool possible1 = true;
                bool possible2 = true;
                possible1 = (dp[m-1][n-1] && s3[m-1]==s1[n-1]);
                if(m-1 >= n) 
                {
                    possible2 = (dp[m-1][n] && s3[m-1]==s2[m-1-n]);
                    dp[m][n] = possible1 || possible2;
                }
                else dp[m][n] = possible1;
            }
        }
    }
    return dp[size][size1];
}

int main()
{
    string s1("aabcc");
    string s2("dbbca");
    string s3("aadbbcbcac");
    string s4("aadbbbaccc");
    cout<<isInterleave(s1, s2, s3)<<endl;
    cout<<isInterleave(s1, s2, s4)<<endl;

    return 0;
}

