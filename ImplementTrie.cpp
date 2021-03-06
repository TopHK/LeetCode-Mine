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

    bool search(string word)
    {
        TrieNode* p = root;
        int size = word.size();
        for(int i=0; i<size; ++i)
        {
            int c = word[i]-'a';
            if(!p->next[c]) return false;
            p = p->next[c];
        }
        return p->isString;
    }

    bool startsWith(string prefix)
    {
        if(prefix.empty()) return false;
        TrieNode *p = root;
        int size = prefix.size();
        for(int i=0; i<size; ++i)
        {
            int c = prefix[i]-'a';
            if(!p->next[c]) return false;
            p = p->next[c];
        }
        return true; 
    }
private:
    TrieNode* root;
};
