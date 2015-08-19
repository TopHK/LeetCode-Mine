/*************************************************************************
	> File Name: SubstringWithConcatenationOfAllWords.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月15日 星期三 20时59分18秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

/*
bool check(const map<string, int> concat, vector<int>& result)
{
    bool found = true;
    for(map<string, int>::iterator it = concat.begin(); it != concat.end(); ++it)
    {
        if(it->second != 0) 
        {
            found = false;
            break;
        }
    }
    if(found)
        result.push_back(i);
}
*/

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> result;
    int sizeOfS = s.size();
    int sizeOfWords = words.size();
    if(sizeOfWords == 0 || sizeOfS == 0) return result;
    int lenOfWord = words[0].size();
    int len = lenOfWord * sizeOfWords;
    unordered_map<string, int> dict;
    for(int i=0; i<sizeOfWords; ++i)
        dict[words[i]]++;

    for(int i=0; i<lenOfWord; ++i)
    {
        unordered_map<string, int> concat;
        for(int start = i, end = i, count = 0; end + n <= sizeOfS; end += lenOfWord)
        {
            string currentStr = s.substr(end, lenOfWord);
            if(dict.find(currentStr) == dict.end()) 
            {
                start = end + lenOfWord;
                concat.clear();
                count = 0;
                continue;
            }
            while(concat.find(currentStr) != concat.end() && concat[currentStr] >= dict[currentStr])
            {
                string subStart = s.substr(start, lenOfWord);
                concat[subStart]--;
                start += lenOfWord;
                --count;
            }
            concat[currentStr]++;
            ++count;
            if(count != sizeOfWords) continue;
            result.push_back(start);
        }
    }
    return result;
}

void print(const vector<int>& result)
{
    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;
}

int main()
{
    string s("barfoothefoobarman");
    string strs[] = {"foo", "bar"};
    vector<string> words(strs, strs+sizeof(strs)/sizeof(strs[0]));
    vector<int> result = findSubstring(s, words);
    print(result);

    return 0;
}
