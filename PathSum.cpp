/*************************************************************************
	> File Name: PathSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月25日 星期四 11时27分37秒
 ************************************************************************/

#include<iostream>
using namespace std;

bool hasPathSumCore(TreeNode* root, int currentSum, const int& sum)
{
    if(!root->left && !root->right) return currentSum==sum;
    else 
    {
        bool isLeftValid = false;
        bool isRightValid = false;
        if(root->left) isLeftValid = hasPathSumCore(root->left, currentSum+root->left->val, sum);
        if(root->right) isRightValid = hasPathSumCore(root->right, currentSum+root->right->val, sum);
        return isLeftValid || isRightValid;
    }
}

bool hasPathSum(TreeNode* root, int sum)
{
    if(!root) return false;
    int currentSum = root->val;
    return hasPathSumCore(root, currentSum, sum);
}

