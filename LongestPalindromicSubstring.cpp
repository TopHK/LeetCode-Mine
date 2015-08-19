/*************************************************************************
	> File Name: LongestPalindromicSubstring.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月06日 星期一 12时05分10秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution 
{
private:
    int tailI, tailJ;
    int maxLen;
public:
//    string longestPalindromeCore(string s1, string s2)
//    {
//        if(s1 == s2) return s1;
//        maxLen = 0;
//        tailI = 0;
//        tailJ = 0;
//        int size = s1.size();
//        vector<int> temp(size+1, 0);
//        vector<vector<int> > dp(size+1, temp);
//        for(int i=1; i<=size; ++i)
//        {
//            for(int j=1; j<=size; ++j)
//            {
//                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
//                else dp[i][j] = 0;
//                if(dp[i][j] > maxLen)
//                {
//                    maxLen = dp[i][j];
//                    tailI = i-1;
//                    tailJ = j-1;
//                    cout<<tailI<<","<<tailJ<<","<<maxLen<<endl;
//                }
//            }
//        }
//        string result = s1.substr(tailI-maxLen+1, maxLen);
//        return result;
//    }
    
    bool validPalindrome(const string& s1, const string& s2, int tailI, int tailJ, int len)
    {
        string str1 = s1.substr(tailI-len+1, len);
        string str2 = s2.substr(tailJ-len+1, len);
        reverse(str1.begin(), str1.end());
        return str1 == str2;
    }
    string longestPalindromeCore(string s1, string s2)
    {
        if(s1 == s2) return s1;
        maxLen = 0;
        tailI = 0;
        tailJ = 0;
        int size = s1.size();
        for(int k=1; k<=size*2; ++k)
        {
            int start1, start2;
            int currentLen;
            if(k <= size)
            {
                start1 = 0;
                start2 = size-k;
                currentLen = k;
            }
            else 
            {
                start1 = k-size;
                start2 = 0;
                currentLen = 2*size-k;
            }
            int tempSubLen = 0;
            while(currentLen--)
            {
                if(s1[start1] == s2[start2]) tempSubLen += 1;
                else tempSubLen = 0;
                if(tempSubLen>maxLen && validPalindrome(s1, s2, start1, start2, tempSubLen))
                {
                    maxLen = tempSubLen;
                    tailI = start1;
                    tailJ = start2;
                }
                start1++;
                start2++;
            }
        }
        string result = s1.substr(tailI-maxLen+1, maxLen);
        return result;
    }
    string longestPalindrome(string s)
    {
        if(s.size() < 2) return s;
        string s2(s);
        reverse(s2.begin(), s2.end());
        return longestPalindromeCore(s, s2);
    }
};

int main()
{
    Solution sol;
    string s("bcddcac");
    cout<<sol.longestPalindrome(s)<<endl;

    return 0;
}

