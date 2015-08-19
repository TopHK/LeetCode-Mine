/*************************************************************************
	> File Name: PopulatingNextRightPointersInEachNode.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 13时43分29秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int depthOfTree(TreeLinkNode* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return max(depthOfTree(root->left), depthOfTree(root->right)) + 1;
}

void connect2(TreeLinkNode* root)
{
    if(!root || (!root->left&&!root->right)) return;
    int depth = depthOfTree(root);
    vector<vector<TreeLinkNode*> > levelNodes(depth);
    queue<TreeLinkNode*> nodesQueue;
    queue<int> levelQueue;

    TreeLinkNode* currentNode = root;
    int currentLevel = 0;
    nodesQueue.push(currentNode);
    levelQueue.push(currentLevel);
   
    while(!nodesQueue.empty())
    {
        currentNode = nodesQueue.front();
        nodesQueue.pop();
        currentLevel = levelQueue.front();
        levelQueue.pop();

        if(!levelNodes[currentLevel].empty())
        {
            int size = levelNodes[currentLevel].size();
            levelNodes[currentLevel][size-1]->next = currentNode;
        }
        levelNodes[currentLevel].push_back(currentNode);
        currentLevel++;

        if(currentNode->left)
        {
            nodesQueue.push(currentNode->left);
            levelQueue.push(currentLevel);
        }
        if(currentNode->right)
        {
            nodesQueue.push(currentNode->right);
            levelQueue.push(currentLevel);
        }
    }
}


void connect(TreeLinkNode* root)
{
    if(!root || !root->left&&!root->right) return;
    while(root->left)
    {
        TreeLinkNode* currentLeftNode = root;
        while(root->next)
        {
            root->left->next = root->right;
            root->right->next = root->next->left;
            root = root->next;
        }
        root->left->next = root->right;
        root = currentLeftNode->left;
    }
}
