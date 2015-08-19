/*************************************************************************
	> File Name: ImplementTrie.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月29日 星期一 16时52分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

class TrieNode
{
public:
    TrieNode* next[26];
    bool isString;
    TrieNode()
    {
        for(int i=0; i<26; ++i) next[i] = NULL;
        isString = false;
    }
};

class Trie 
{
public:
    Trie() 
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        int size = word.size();
        TrieNode *p = root;
        for(int i=0; i<size; ++i)
        {
            int c = word[i]-'a';
            if(!p->next[c])
            {
                TrieNode *tempNode = new TrieNode();
                p->next[c] = tempNode;
            }
            p = p->next[c];
        }
        p->isString = true;
    }

    bool searchCore(TrieNode* start, string subWord)
    {
        char ch = subWord[0];
        if(ch != '.')
        {
            int c = ch-'a';
            if(!start->next[c]) return false;
            start = start->next[c];
            if(subWord.size() == 1)
                return start->isString;
            else return searchCore(start, subWord.substr(1));
        }
        else 
        {
            for(int j=0; j<26; ++j)
            {
                if(start->next[j]) 
                {
                    TrieNode* startTemp = start->next[j];
                    if(subWord.size() == 1)
                    {
                        if(startTemp->isString) return true;
                    }
                    else if(searchCore(startTemp, subWord.substr(1))) return true;   
                }
            }
            return false;
        }
    }
    bool search(string word)
    {
        TrieNode* p = root;
        return searchCore(p, word);
    }

private:
    TrieNode* root;
};

class WordDictionary 
{
private:
    Trie trie;
public:
    WordDictionary(){}
    void addWord(string word)
    {
        trie.insert(word);
    }
    bool search(string word)
    {
        return trie.search(word);
    }
};

int main()
{
    WordDictionary wordDict;
    wordDict.addWord("add");
    cout<<wordDict.search(".at")<<endl;
    wordDict.addWord("bat");
    cout<<wordDict.search(".at")<<endl;
//    cout<<wordDict.search("an.")<<endl;
//    cout<<wordDict.search("a.d.")<<endl;
//    cout<<wordDict.search("b.")<<endl;
//    cout<<wordDict.search("a.d")<<endl;
//    cout<<wordDict.search(".")<<endl;
//    cout<<wordDict.search(".at")<<endl;

    return 0;
}
