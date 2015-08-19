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

vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> result;
    if(!root) return result;
    stack<TreeNode* > nodes;
    nodes.push(root);
   
    TreeNode* currentNode;
    while(!nodes.empty())
    {
        // left subnode into the stack
        currentNode = nodes.top();
        while(currentNode->left)
        {
            currentNode = currentNode->left;
            nodes.push(currentNode);
        }
        nodes.pop();
        result.push_back(currentNode->val);

        // visit the nodes in stack until the current node has right subtree
        while(!currentNode->right && !nodes.empty())
        {
            currentNode = nodes.top();
            result.push_back(currentNode->val);
            nodes.pop();
        }
        if(currentNode->right) nodes.push(currentNode->right);
    }
    return result;
}




