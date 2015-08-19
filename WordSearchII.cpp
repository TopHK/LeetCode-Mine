#include<iostream>
#include<set>
#include<string>
#include<vector>
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

class Solution 
{
private:
    set<string> resultSet;
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) 
    {
        Trie trie;
        for(int i = 0; i < words.size(); ++i)
            trie.insert(words[i]);
        int N = board.size(), M = board[0].size();
        vector<vector<char> > avail(N, vector<char>(M, 'o'));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                existRe(board, "", i, j, avail, trie);
        vector<string> result(resultSet.begin(), resultSet.end());
        return result;
    }
    
    void existRe(const vector<vector<char> > &board, string word, int i, int j, vector<vector<char> > &avail, Trie& trie)
    {
        int N = board.size(), M = board[0].size();
        if (i < 0 || i >= N || j < 0 || j >= M) return;
        if (avail[i][j] == 'x') return;
        
        word += board[i][j];
        if(!trie.startsWith(word)) return;
        if(trie.search(word)) 
            resultSet.insert(word);

        avail[i][j] = 'x';
        existRe(board, word, i-1, j, avail, trie);
        existRe(board, word, i+1, j, avail, trie);
        existRe(board, word, i, j-1, avail, trie);
        existRe(board, word, i, j+1, avail, trie);
        avail[i][j] = 'o';
    }
};
