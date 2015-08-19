/*************************************************************************
	> File Name: UniqueBinarySearchTreesII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月25日 星期四 22时13分55秒
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

/*
TreeNode* generateTreesCore(int begin, int end)
{
    if(begin > end) return NULL;
    for(int i=begin; i<=end; ++i)
    {
        TreeNode* root = new TreeNode(i);
        root->left = generateTreesCore(begin, i-1);
        root->right = generateTreesCore(i+1, end);
        return root;
    }
}

vector<TreeNode* > generateTrees(int n)
{
    vector<TreeNode* > result;
    if(n == 0)
        result.push_back(NULL);
    for(int i=1; i<=n; ++i)
    {
        TreeNode* root = new TreeNode(i);
        root->left = generateTreesCore(1, i-1);
        root->right = generateTreesCore(i+1, n);
        result.push_back(root);
    }
    return result;
}
*/

/*
TreeNode* generateTreesCore(int begin, int end, vector<TreeNode*>& result)
{
    if(begin > end) return NULL;
    if(begin == end)
    {
        TreeNode* root = new TreeNode(begin);
        return root;
    }
    for(int i=begin; i<=end; ++i)
    {
        TreeNode* root = new TreeNode(i);
        root->left = generateTreesCore(begin, i-1, result);
        root->right = generateTreesCore(i+1, end, result);
        result.push_back(root);
    }
}

vector<TreeNode* > generateTrees(int n)
{
    vector<TreeNode* > result;
    if(n == 0)
        result.push_back(NULL);
    generateTreesCore(1, n, result);
    return result;
}
*/

vector<TreeNode* > generateTreesCore(int begin, int end)
{
    vector<TreeNode* > result;
    if(begin > end)
    {
        result.push_back(NULL);
        return result;
    }

    for(int i=begin; i<=end; ++i)
    {
        vector<TreeNode* > leftNodes = generateTreesCore(begin, i-1);
        vector<TreeNode* > rightNodes = generateTreesCore(i+1, end);

        for(int m=0; m<leftNodes.size(); ++m)
        {
            for(int n=0; n<rightNodes.size(); ++n)
            {
                TreeNode* root = new TreeNode(i);
                root->left = leftNodes[m];
                root->right = rightNodes[n];
                result.push_back(root);
            }
        }
    }
    return result;
}

vector<TreeNode*> generateTrees(int n)
{
    return generateTreesCore(1, n);
}
