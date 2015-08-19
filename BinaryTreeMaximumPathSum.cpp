/*************************************************************************
	> File Name: BinaryTreeMaximumPathSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月14日 星期二 11时30分12秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution2 
{
private:
    int leftSum;
    int rightSum;
    int maxSum;
public:
    void maxPathSumCore2(TreeNode* root, int currentSum)
    {
        if(!root->left && !root->right)
        {
            if(leftSum == -1) leftSum = currentSum;
            else if(rightSum == -1) 
            {
                leftSum = max(leftSum, currentSum);
                rightSum = max(leftSum, currentSum);
            }
            else if(currentSum > leftSum) leftSum = currentSum;
            else if(currentSum > rightSum) rightSum = currentSum;
            return;
        }
        if(root->left) maxPathSumCore(root->left, currentSum+root->left->val);
        if(root->right) maxPathSumCore(root->right, currentSum+root->right->val);
    }

    void maxPathSumCore(TreeNode* root, int currentSum)
    {
        if(!root->left && !root->right)
        {
            if(currentSum > leftSum) leftSum = currentSum;
            else if(currentSum > rightSum) rightSum = currentSum;
            return;
        }
        if(root->left) maxPathSumCore(root->left, currentSum+root->left->val);
        if(root->right) maxPathSumCore(root->right, currentSum+root->right->val);
    }
    void maxPathSumCore2(TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            if(maxSum < root->val) maxSum = root->val;
            return;
        }
        if(root->left)
        {
            TreeNode* left = root->left;
            leftSum = left->val;
            rightSum = left->val;
            int currentSum = left->val;
            maxPathSumCore(left, currentSum);
            int maxSumTemp = (leftSum + rightSum - left->val);           
            if(maxSum < maxSumTemp) maxSum = maxSumTemp;
        }
        if(root->right)
        {
            TreeNode* right = root->right;
            rightSum = right->val;
            rightSum = right->val;
            int currentSum = right->val;
            maxPathSumCore(right, currentSum);
            int maxSumTemp = (rightSum + rightSum - right->val);           
            if(maxSum < maxSumTemp) maxSum = maxSumTemp;
        }
    }

    int maxPathSum(TreeNode* root)
    {
        maxSum = root->val;
        maxPathSumCore2(root);
        return maxSum;
    }
};

class Solution 
{
private:
    int maxSum;
public:
    int maxPathSumCore(TreeNode* root)
    {
        if(!root) return 0;
        int sum = root->val;
        int leftValue = maxPathSumCore(root->left);
        int rightValue = maxPathSumCore(root->right);
        if(leftValue > 0) sum += leftValue;
        if(rightValue > 0) sum += rightValue;
        maxSum = max(sum, maxSum);
        return max(leftValue, rightValue)>0 ? root->val+max(leftValue, rightValue) : root->val;
    }
    int maxPathSum(TreeNode* root)
    {
        maxSum = INT_MIN;
        maxPathSumCore(root);
        return maxSum;
    }
};
