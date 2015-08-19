/*************************************************************************
	> File Name: BinaryTreeInorderTraversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 11时10分44秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> preorderTraversal(TreeNode* root)
{
    vector<int> result;
    if(!root) return result;
    stack<TreeNode* > nodes;
    nodes.push(root);
    result.push_back(root->val);
   
    TreeNode* currentNode;
    while(!nodes.empty())
    {
        // left subnode into the stack
        currentNode = nodes.top();
        while(currentNode->left)
        {
            currentNode = currentNode->left;
            result.push_back(currentNode->val);
            nodes.push(currentNode);
        }

        while(!currentNode->right && !nodes.empty())
        {
            nodes.pop();
            if(!nodes.empty()) currentNode = nodes.top();
        }
        if(currentNode->right) 
        {
            nodes.pop();
            currentNode = currentNode->right;
            nodes.push(currentNode);   
            result.push_back(currentNode->val);
        }
    }
    return result;
}




