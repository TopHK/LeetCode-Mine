/*************************************************************************
	> File Name: LowestCommonAncestorOfABinaryTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月16日 星期四 19时56分42秒
 ************************************************************************/

#include<iostream>
#include<list>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution 
{
public:
    bool getNodePath(TreeNode* root, TreeNode* node, list<TreeNode* >& path)
    {
        if(root == node) 
        {
            path.push_back(node);
            return true;   
        }
        path.push_back(root);
        bool found = false;
        if(root->left && getNodePath(root->left, node, path))
            found = true;
        if(!found && root->right && getNodePath(root->right, node, path))
            found = true;
        if(!found) path.pop_back();
        return found;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root || !p || !q) return NULL;
        list<TreeNode* > pathP;
        getNodePath(root, p, pathP);
        list<TreeNode* > pathQ;
        getNodePath(root, q, pathQ);
        list<TreeNode* >::iterator it1 = pathP.begin();
        list<TreeNode* >::iterator it2 = pathQ.begin();
        TreeNode* commonAncestor = root;
        while(it1 != pathP.end() && it2 != pathQ.end())
        {
            if(*it1 == *it2) commonAncestor = *it1;
            else break;
            it1++;
            it2++;
        }
        return commonAncestor;
    }
};

