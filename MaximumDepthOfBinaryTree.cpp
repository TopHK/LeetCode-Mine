/*************************************************************************
	> File Name: MinimumDepthOfBinaryTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 15时23分50秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int maxDepth(TreeNode* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    if(root->left&&!root->right) return maxDepth(root->left) + 1;   
    if(!root->left&&root->right) return maxDepth(root->right) + 1;   
    if(root->left && root->right)
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
