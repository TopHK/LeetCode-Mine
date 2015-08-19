/*************************************************************************
	> File Name: Anagrams.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 11时38分17秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct words
{
    string word;
    int index;
    words(string str, int i):word(str),index(i){}
};

bool operator<(const words& word1, const words& word2)
{
    string str1 = word1.word;
    string str2 = word2.word;
    if(str1.size() < str2.size()) return true;
    else if(str1.size() > str2.size()) return false;
    else return (str1<str2);
}

class Solution 
{
public:
    vector<string> anagrams(vector<string>& strs)
    {
        vector<words> strsIndex;
        for(int i=0; i<strs.size(); ++i)
        {
            string temp(strs[i]);
            sort(temp.begin(), temp.end());
            strsIndex.push_back(words(temp, i));
        }
        sort(strsIndex.begin(), strsIndex.end());
        
//        for(int i=0; i<strsIndex.size(); ++i)
//            cout<<strsIndex[i].word<<" ";
//        cout<<endl;
        vector<string> result;
        vector<words>::iterator it = strsIndex.begin();
        string firstWord = (*it).word;
        int firstIndex = (*it).index;
        strsIndex.erase(it);
        bool firstFound = true;
        while(it != strsIndex.end())
        {
            string currentWord = (*it).word;
            int currentIndex = (*it).index;
            if(currentWord == firstWord)
            {
                if(firstFound)
                {
                    result.push_back(strs[firstIndex]);
                    firstFound = false;
                }
                result.push_back(strs[currentIndex]);
                strsIndex.erase(it);
            }
            else
            {
                firstWord = currentWord;
                firstIndex = currentIndex;
                firstFound = true;
                it++;
            }
        }
        return result;
    }
};


int main()
{
    string strs[] = {"tea", "and", "ate", "eat", "den"};
    vector<string> strings(strs, strs+sizeof(strs)/sizeof(strs[0]));
    Solution sol;
    vector<string> result =  sol.anagrams(strings);
    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;

    return 0;
}
