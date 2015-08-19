/*************************************************************************
	> File Name: ScrambleString.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月02日 星期四 21时09分23秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

// Solution 1
bool isScramble(string s1, string s2)
{
    if(s1.empty() && s2.empty()) return true;
    int size1 = s1.size();
    int size2 = s2.size();
    if(size1 != size2) return false;
    if(size1 == 1) return s1 == s2;

    for(int len=1; len<=size1-1; ++len)
    {
        string s11 = s1.substr(0, len);
        string s12 = s1.substr(len);
        string s21I = s2.substr(0, len);
        string s22I = s2.substr(len);
        string s21II = s2.substr(0, size2-len);
        string s22II = s2.substr(size2-len);

        if((isScramble(s11, s21I) && isScramble(s12, s22I)) ||(isScramble(s11, s22II) && isScramble(s12, s21II)))
            return true;
    }
    return false;
}

// Solution 2: dynamic programming 
bool isScramble2(string s1, string s2)
{
    if(s1.empty() && s2.empty()) return true;
    int size1 = s1.size();
    int size2 = s2.size();
    if(size1 != size2) return false;
    bool dp[size1+1][size1][size1];
    for(int k=1; k<=size1; ++k)
    {
        for(int i=0; i<size1; ++i)
        {
            for(int j=0; j<size1; ++j)
            {
                dp[k][i][j] = false;
                if(k == 1) dp[k][i][j] = (s1[i]==s2[j]);
                for(int s=1; s<k&&!dp[k][i][j]; ++s)
                    if((dp[s][i][j]&&dp[k-s][i+s][j+s]) || (dp[s][i][j+k-s]&&dp[k-s][i+s][j]))
                        dp[k][i][j] = true;
            }
        }
    }
    return dp[size1][0][0];
}

int main()
{
    string str1 = "abcdefghijilmnopq";
    string str2 = "efghijklmnopqcadb";
    if(isScramble2(str1, str2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

