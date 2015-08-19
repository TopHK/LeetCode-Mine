/*************************************************************************
	> File Name: SymmetricTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 10时15分50秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):left(NULL),right(NULL){}
};

void preOrderTraversal(TreeNode* root, vector<char*>& leftNodes)
{
    char str[50] = "#";
    if(!root) 
    {
        leftNodes.push_back(str);
        return;
    }
    sprintf(str, "%d", root->val);
    leftNodes.push_back(str);
    preOrderTraversal(root->left, leftNodes);
    preOrderTraversal(root->right, leftNodes);
}

void rePreOrderTraversal(TreeNode* root, vector<char*>& rightNodes)
{
    char str[50] = "#";
    if(!root) 
    {
        rightNodes.push_back(str);
        return;
    }
    sprintf(str, "%d", root->val);
    rightNodes.push_back(str);
    rePreOrderTraversal(root->right, rightNodes);
    rePreOrderTraversal(root->left, rightNodes);
}

bool isSymmetric(TreeNode* root)
{
    if(!root || !root->left&&!root->right) return true;
    vector<char*> leftNodes;
    vector<char*> rightNodes;
    preOrderTraversal(root->left, leftNodes);
    rePreOrderTraversal(root->right, rightNodes);

    int sizeOfLeft = leftNodes.size();
    int sizeOfRight = rightNodes.size();
    if(sizeOfLeft != sizeOfRight) return false;
    for(int i=0; i<sizeOfLeft; ++i)
        if(strcmp(leftNodes[i],rightNodes[i]) != 0) return false;
    return true;
}


bool isSymmetric(TreeNode* root1, TreeNode* root2)
{
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->val != root2->val) return false;

    return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
}
bool isSymmetric2(TreeNode* root)
{
    return isSymmetric(root, root);
}
