/*************************************************************************
	> File Name: WordBreak.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月30日 星期二 22时20分46秒
 ************************************************************************/

#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution 
{
public:
    /*
    bool wordBreakCore(string s, int start, unordered_set<string>& wordDict)
    {
        if(start == s.size()) return true;
        int len = s.size()-start;
        int numOfMatch = 0;
        for(int i=1; i<=len; ++i)
        {
            if(wordDict.count(s.substr(start, i)) != 0)
            {
                numOfMatch++;
                if(!wordBreakCore(s, start+i, wordDict)) return false;
            }
        }
        return numOfMatch!=0;
    }

    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        if(s.empty()) return false;
        return wordBreakCore(s, 0, wordDict);
    }
    */
    
    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        if(s.empty()) return false;
        int size = s.size();
        vector<bool> canBreak(size+1, false);
        canBreak[0] = true;
        for(int i=1; i<size+1; ++i)
        {
            for(int j=i-1; j>=0; --j) 
            {
                if(canBreak[j] && wordDict.count(s.substr(j, i-j))!=0)
                {
                    canBreak[i] = true;
                    break;
                }
            }
        }
        return canBreak[size];
    }

};

