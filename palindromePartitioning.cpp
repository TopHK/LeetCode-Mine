/*************************************************************************
	> File Name: palindromePartitioning.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月27日 星期六 19时41分35秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution
{
private:
    vector<vector<string> > result;
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
            result.push_back(oneResult);
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
    vector<vector<string> > partition(string s)
    {
        if(s.empty()) return result;
        vector<string> oneResult;
        partitionCore(s, 0, oneResult);
        return result;
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

int main()
{
    string str("aab");
    Solution sol;
    vector<vector<string> > result = sol.partition(str);
    print(result);

    return 0;
}

