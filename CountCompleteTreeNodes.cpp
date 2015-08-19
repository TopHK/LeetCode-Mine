/*************************************************************************
	> File Name: CountCompleteTreeNodes.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月06日 星期一 16时29分59秒
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

int countNodes(TreeNode* root)
{
    if(!root) return 0;
    int leftDepth = 0;
    int rightDepth = 0; 
    TreeNode* p = root;
    while(p) 
    {
        p = p->left;
        leftDepth++;
    }
    p = root;
    while(p) 
    {
        p = p->right;
        rightDepth++;
    }
    if(leftDepth == rightDepth) return (2<<(leftDepth-1))-1;
    return countNodes(root->left)+countNodes(root->right)+1;
}
