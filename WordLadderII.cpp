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
#include<algorithm>
#include<unordered_set>
using namespace std;

void buildResult(map<string, vector<string> >& traces, vector<vector<string> >& result, vector<string>& onePath, string word)
{
    if(traces.count(word) == 0)
    {
        vector<string> copyPath(onePath);
        copyPath.push_back(word);
        reverse(copyPath.begin(), copyPath.end());
        result.push_back(copyPath);
        return;
    }
    const vector<string>& s = traces[word];
    onePath.push_back(word);
    for(vector<string>::const_iterator it = s.begin(); it != s.end(); ++it)
        buildResult(traces, result, onePath, *it);
    onePath.pop_back();
}

vector<vector<string> > findLadders(string start, string end, unordered_set<string>& dict)
{
    map<string, vector<string> > traces;
    vector<unordered_set<string> > level(2);
    int current = 0;
    int previous = 1;
    level[current].insert(start);
    dict.insert(end);

    while(true)
    {
        previous = !previous;
        current = !current;
        level[current].clear();

        for(unordered_set<string>::iterator it = level[previous].begin(); it != level[previous].end(); ++it)
            dict.erase(*it);
        for(unordered_set<string>::iterator it = level[previous].begin(); it != level[previous].end(); ++it)
        {
            string word = *it;
            for(size_t i = 0; i < word.size(); ++i)
            {
                char before = word[i];
                for(char c = 'a'; c <= 'z'; ++c)
                {
                    if(c == before) continue;
                    word[i] = c;
                    if(dict.find(word) != dict.end())
                    {
                        traces[word].push_back(*it);
                        level[current].insert(word);
                    }
                }
                word[i] = before;
            }
        }
        if(level[current].empty() || level[current].count(end) > 0) break;
    }
    vector<vector<string> > result;
    vector<string> onePath;
    if(!traces.empty()) 
        buildResult(traces, result, onePath, end);
    return result;
}
