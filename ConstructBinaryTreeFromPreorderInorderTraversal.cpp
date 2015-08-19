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
    TreeNode* buildTreeCore(vector<int>& preorder, int preorderStart, int preorderLast, vector<int>& inorder, int inorderStart, int inorderLast)
    {
        if(preorderStart>preorderLast || inorderStart>inorderLast) return NULL;
        int rootValue = preorder[preorderStart];
        TreeNode* root = new TreeNode(rootValue);
        if(preorderStart==preorderLast && inorderStart==inorderLast) return root;

        int rootOfInorder;
        for(rootOfInorder=inorderStart; rootOfInorder<=inorderLast; rootOfInorder++) 
            if(inorder[rootOfInorder] == rootValue) break;

        int inorderStartOfLeft = inorderStart;
        int inorderLastOfLeft = rootOfInorder-1; 
        int inorderStartOfRight = rootOfInorder+1;
        int inorderLastOfRight = inorderLast;
        int preorderStartOfLeft = preorderStart+1;
        int preorderLastOfLeft = preorderStart+(rootOfInorder-inorderStart);
        int preorderStartOfRight = preorderLastOfLeft+1; 
        int preorderLastOfRight = preorderLast;


        root->left = buildTreeCore(preorder, preorderStartOfLeft, preorderLastOfLeft, inorder, inorderStartOfLeft, inorderLastOfLeft);
        root->right = buildTreeCore(preorder, preorderStartOfRight, preorderLastOfRight, inorder, inorderStartOfRight, inorderLastOfRight);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTreeCore(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

};
