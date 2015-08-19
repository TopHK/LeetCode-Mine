/*************************************************************************
    > File Name: MinimumWindowSubstring.cpp
    > Author: 
    > Mail: 
    > Created Time: 2015年07月16日 星期四 10时07分19秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<limits.h>
#include<map>
using namespace std;

/*
string minWindow(string s, string t)
{
    if(s.empty() || t.empty() || s.size() < t.size()) return "";
    int minSize = s.size() + 1;
    int beginPos = -1;
    int endPos = -1;
    map<char, int> dict;
    for(int i = 0; i < t.size(); ++i)
        dict[t[i]]++;

    for(int i=0; i <= s.size()-t.size(); ++i)
    {
        if(t.find(s[i], 0) == string::npos) continue;
        map<char, int> found(dict);
        for(int j=i; j<s.size(); ++j)
        {
            if(t.find(s[j], 0) != string::npos) 
            {
                if(found.find(s[j]) != found.end())
                {
                    found[s[j]]--;
                    if(found[s[j]] == 0) found.erase(s[j]);
                }
            }
            if(found.empty())
            {
                int len = j-i+1;
                if(len < minSize)
                {
                    minSize = len;
                    beginPos = i;
                    endPos = j;
                }
                break;
            }
        }
        if(!found.empty())
            break;
    }
    if(beginPos != -1) return s.substr(beginPos, minSize);
    else return "";
}
*/

string minWindow(string s, string t)
{
    if(s.empty() || t.empty() || s.size() < t.size()) return "";
    map<char, int> dict;
    map<char, int> found;
    for(int i = 0; i < t.size(); ++i)
    {
        dict[t[i]]++;
        found[t[i]] = 0;
    }

    int startMin = -1;
    int endMin = s.size();
    int count = 0;
    for(int start = 0, end = 0; end < s.size(); end++)
    {
        if(dict.find(s[end]) == dict.end()) continue;
        if(found[s[end]] < dict[s[end]]) count++;
        found[s[end]]++;
        if(count != t.size()) continue;
        cout<<"start:"<<start<<",end:"<<end<<endl;
        while(start < end)
        {
            if(dict.find(s[start]) != dict.end())
            {
                if(found[s[start]] == dict[s[start]]) break;
                found[s[start]]--;
            }
            start++;
        }
        cout<<"start:"<<start<<",end:"<<end<<endl;
        if(end - start < endMin - startMin)
        {
            endMin = end;
            startMin = start;
        }
    }
    return startMin == -1 ? "" : s.substr(startMin, endMin-startMin+1);
}

int main()
{
    string s("asbadcfg");
    string t("abc");
    cout<<minWindow(s, t)<<endl;

    return 0;
}

