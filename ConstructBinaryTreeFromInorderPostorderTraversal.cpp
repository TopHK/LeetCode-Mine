/*************************************************************************
	> File Name: ConstructBinaryTreeFromInorderPostorderTraversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月27日 星期六 11时58分53秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution
{
public:
    TreeNode* buildTreeCore(vector<int>& inorder, int inorderStart, int inorderLast, vector<int>& postorder, int postorderStart, int postorderLast)
    {
        if(inorderStart>inorderLast || postorderStart>postorderLast) return NULL;
        int rootValue = postorder[postorderLast];
        TreeNode* root = new TreeNode(rootValue);
        if(inorderStart==inorderLast && postorderStart==postorderLast) return root;

        int rootOfInorder;
        for(rootOfInorder=inorderStart; rootOfInorder<=inorderLast; rootOfInorder++) 
            if(inorder[rootOfInorder] == rootValue) break;
        int inorderStartOfLeft = inorderStart;
        int inorderLastOfLeft = rootOfInorder-1;
        int inorderStartOfRight = rootOfInorder+1;
        int inorderLastOfRight = inorderLast;

        int postorderStartOfLeft = postorderStart;
        int postorderLastOfLeft = postorderstartOfLeft+(rootOfInorder-inorderStart-1);
        int postorderStartOfRight = postorderLastOfLeft+1;
        int postorderLastOfRight = postorderLast-1;
        root->left = buildTreeCore(inorder, inorderStartOfLeft, inorderLastOfLeft, postorder, postorderStartOfLeft, postorderLastOfLeft);
        root->right = buildTreeCore(inorder, inorderStartOfRight, inorderLastOfRight, postorder, postorderStartOfRight, postorderLastOfRight);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildTreeCore(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

};
