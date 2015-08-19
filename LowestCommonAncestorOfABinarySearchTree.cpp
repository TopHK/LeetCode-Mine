/*************************************************************************
	> File Name: LowestCommonAncestorOfABinarySearchTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月16日 星期四 19时14分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root || !p || !q) return NULL;
    TreeNode* r = root;
    while(r)
    {
        if(r->val > p->val && r->val > q->val)
        {
            r = r->left;
            continue;
        }
        if(r->val < p->val && r->val < q->val)
        {
            r = r->right;
            continue;
        }
        break;
    }
    return r;
}
