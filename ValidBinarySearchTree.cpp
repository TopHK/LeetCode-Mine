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
    TreeNode* preNode;
public:
    Solution():preNode(NULL){}
    bool isValidBST(TreeNode* root)
    {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;
        if(preNode!=NULL && root->val<=preNode->val) return false;
        preNode = root;
        return isValidBST(root->right);
    }
};
