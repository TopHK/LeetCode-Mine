/*************************************************************************
	> File Name: KthSmallestElementInaBST.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月06日 星期一 20时28分45秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Solution 
{
private:
    int count;
    int kValue;
public:
    void kthSmallestCore(TreeNode* root, int k)
    {
        if(!root) return;
        kthSmallestCore(root->left, k);
        count++;
        if(count == k)
        {
            kValue = root->val;
            return;
        }
        kthSmallestCore(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k)
    {
        count = 0;
        kthSmallestCore(root, k);
        return kValue;
    }
};

