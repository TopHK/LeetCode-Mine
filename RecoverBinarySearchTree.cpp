/*************************************************************************
	> File Name: ValidBinarySearchTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月30日 星期二 20时20分27秒
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

class Solution 
{
private:
    TreeNode* firstNode;
    TreeNode* secondNode;
    TreeNode* preNode;
public:
    Solution():firstNode(NULL), secondNode(NULL), preNode(NULL){}
    void isValidBST(TreeNode* root)
    {
        if(!root) return;
        isValidBST(root->left);
        if(preNode!=NULL && root->val<=preNode->val)
        {
            if(!firstNode)
            {
                firstNode = preNode;
                secondNode = root;
            }
            else 
            {
                secondNode = root;
                return;
            }
        }
        preNode = root;
        isValidBST(root->right);
    }
    void recoverTree(TreeNode* root)
    {
        if(!root || !root->left&&!root->right) return;
        isValidBST(root);
        int tempVal = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = tempVal;
    }
};
