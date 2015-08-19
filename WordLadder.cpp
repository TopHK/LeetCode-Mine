/*************************************************************************
	> File Name: WordLadder.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月15日 星期三 22时15分34秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
{
    queue<pair<string, int> > wordsQueue;
    wordsQueue.push(make_pair(beginWord, 1));

    while(!wordsQueue.empty())
    {
        pair<string, int> front = wordsQueue.front();
        wordsQueue.pop();
        string currentStr = front.first;

        for(int i = 0; i < currentStr.size(); ++i)
        {
            char before = currentStr[i];
            for(char ch = 'a'; ch <= 'z'; ++ch)
            {
                currentStr[i] = ch;
                if(currentStr == endWord)
                    return front.second + 1;
                if(wordDict.find(currentStr) != wordDict.end())
                {
                    wordsQueue.push(make_pair(currentStr, front.second + 1));
                    wordDict.erase(currentStr);
                }
            }
            currentStr[i] = before;
        }
    }
    return 0;
}

