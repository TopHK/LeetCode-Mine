/*************************************************************************
	> File Name: SumRootToLeftNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 09时12分58秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int pathNum(const vector<int>& num)
{
    int number = 0;
    for(int i=0; i<num.size(); ++i)
        number = number*10+num[i];
    return number;
}

void preOrderTraversal(TreeNode* root, int& sum, vector<int>& num)
{
    if(!root->left && !root->right) 
    {
        num.push_back(root->val);
        sum += pathNum(num);
        num.pop_back();
        return;
    }
    num.push_back(root->val);
    if(root->left)
        preOrderTraversal(root->left, sum, num);   
    if(root->right)
        preOrderTraversal(root->right, sum, num);   
    num.pop_back();
}

int sumNumbers(TreeNode* root)
{
    int sum = 0;
    vector<int> num;
    if(!root) return 0;
    preOrderTraversal(root, sum, num);

    return sum;
}

