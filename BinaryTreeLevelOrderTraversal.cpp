/*************************************************************************
	> File Name: BinaryTreeLevelOrderTraversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 20时00分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int depthOfTree(TreeNode* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return max(depthOfTree(root->left), depthOfTree(root->right)) + 1;
}

vector<vector<int> > levelOrder(TreeNode* root)
{
    int depth = depthOfTree(root);
    queue<TreeNode* > nodes;
    queue<int> level;
    vector<vector<int> > result(depth);
    if(!root) return result;
    nodes.push(root);
    level.push(0);

    while(!nodes.empty())
    {
        TreeNode* currentNode = nodes.front();
        nodes.pop();
        int currentLevel = level.front();
        level.pop();
        result[currentLevel].push_back(currentNode->val);

        currentLevel++;
        if(currentNode->left)
        {
            nodes.push(currentNode->left);
            level.push(currentLevel);
        }
        if(currentNode->right)
        {
            nodes.push(currentNode->right);
            level.push(currentLevel);
        }
    }
    return result;
}
