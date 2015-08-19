/*************************************************************************
	> File Name: BalancedBinaryTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 19时30分00秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int depthOfTree(TreeNode* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return max(depthOfTree(root->left), depthOfTree(root->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
    if(!root) return true;
    int depthOfLeft = depthOfTree(root->left);
    int depthOfRight = depthOfTree(root->right);
    int diff = abs(depthOfLeft - depthOfRight);
    return diff<=1 && isBalanced(root->left) && isBalanced(root->right);
}

