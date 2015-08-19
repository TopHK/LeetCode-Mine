/*************************************************************************
	> File Name: ConvertSortedArrayToBinarySearchTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 19时55分04秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums, int begin, int end)
{
    TreeNode* root;
    if(begin == end)
    {
        root = new TreeNode(nums[begin]);
        return root;
    }

    int middle= begin+((end-begin)>>1);
    root = new TreeNode(nums[middle]);
    if(begin <= middle-1)
        root->left = sortedArrayToBST(nums, begin, middle-1);
    if(end >= middle+1)
        root->right = sortedArrayToBST(nums, middle+1, end);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    TreeNode* root;
    if(nums.empty()) return NULL;
    root = sortedArrayToBST(nums, 0, nums.size()-1);
    return root;
}

