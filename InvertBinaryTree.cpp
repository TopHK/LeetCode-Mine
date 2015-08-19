/*************************************************************************
	> File Name: InvertBinaryTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 22时33分10秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* invertTree(TreeNode* root)
{
    if(!root || !root->left&&!root->right) return root;
    invertTree(root->left);
    invertTree(root->right);
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}
