/*************************************************************************
	> File Name: BinaryTreePostOrderTraversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 21时27分16秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<int> postorderTraversal(TreeNode* root)
{
    vector<int> result;
    if(!root)  return result;
    stack<TreeNode* > nodesStack;
    map<TreeNode*, bool> nodesVisited;
    nodesStack.push(root);
    TreeNode* currentNode;

    while(!nodesStack.empty())
    {
        currentNode = nodesStack.top();
        while(currentNode->left || currentNode->right)
        {
            while(currentNode->left)
            {
                currentNode = currentNode->left;
                nodesStack.push(currentNode);
            }
            
            if(currentNode->right)
            {
                currentNode = currentNode->right;
                nodesStack.push(currentNode);
            }
        }
        result.push_back(currentNode->val);
        nodesVisited[currentNode] = true;
        nodesStack.pop();

        while(!nodesStack.empty())
        {
            currentNode = nodesStack.top();
            if(!currentNode->right || nodesVisited.find(currentNode->right)!=nodesVisited.end())
            {
                result.push_back(currentNode->val);
                nodesVisited[currentNode] = true;
                nodesStack.pop();
            }
            else if(currentNode->right && nodesVisited.find(currentNode)==nodesVisited.end())
            {
                currentNode = currentNode->right;
                nodesStack.push(currentNode);
                break;
            }
        }
    }
    return result;
}
