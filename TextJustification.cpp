/*************************************************************************
	> File Name: TextJustification.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月19日 星期日 13时50分42秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> result;
    if(words.empty()) return result;
    int numOfCharacters = 0;
    int countOfWords = 0;
    int numOfBlanks = 0;
    int numOfRestBlanks = 0;
    int lastPos = 0;
    for(int i = 0; i < words.size(); ++i)
    {
        numOfCharacters += words[i].size();
        countOfWords++;
        if(maxWidth - numOfCharacters >= countOfWords - 1)
            continue;
        countOfWords--;
        numOfCharacters -= words[i].size();
        string line;
        if(countOfWords == 1)
        {
            line = words[i - 1];
            string blankStr(maxWidth - line.size(), ' ');
            line += blankStr;
        }
        else 
        {
            numOfBlanks = (maxWidth - numOfCharacters)/(countOfWords - 1);
            string blankStr(numOfBlanks, ' ');
            numOfRestBlanks = (maxWidth - numOfCharacters) - numOfBlanks * (countOfWords - 1);

            for(int j = i - countOfWords; j <= i-1; ++j)
            {
                line += words[j];
                if(j == i - 1) break;
                line += blankStr;
                if(numOfRestBlanks != 0) 
                {
                    line += " ";
                    numOfRestBlanks--;
                }
            }
        }
        result.push_back(line);
        numOfCharacters = words[i].size();
        countOfWords = 1;
        lastPos = i;
    }

    string line;
    line += words[words.size() - countOfWords];
    for(int j = words.size() - countOfWords + 1; j < words.size(); ++j)
        line += (" " + words[j]);
    string blankStr(maxWidth - line.size(), ' ');
    line += blankStr;
    result.push_back(line);
    return result;
}

void print(const vector<string>& result)
{
    for(int i = 0; i < result.size(); ++i)
        cout<<result[i]<<",size:"<<result[i].size()<<endl;
}

int main()
{
    string strs[] = {"Don't", "go", "around", "saying", "the", "world", "owns", "you", "a", "living;", "the", "world", "owes", "you",
                    "nothing;", "it", "was", "here", "first."};
    vector<string> words(strs, strs + sizeof(strs)/sizeof(strs[0]));
    int maxWidth = 30;
    vector<string> result = fullJustify(words, maxWidth);
    print(result);
    return 0;
}

