/*************************************************************************
	> File Name: BinaryTreeRightSideView.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 18时55分40秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void levelTraversal(TreeNode* root, vector<vector<int> >& nodes)
{
    if(!root) return;
    queue<TreeNode* > nodesQueue;
    queue<int> level;
    nodesQueue.push(root);
    level.push(0);
    TreeNode* currentNode;
    int currentLevel;

    while(!nodesQueue.empty())
    {
        currentNode = nodesQueue.front();
        nodesQueue.pop();
        currentLevel = level.front();
        nodes[currentLevel].push_back(currentNode->val);
        currentLevel++;
        level.pop();

        if(currentNode->left)
        {
            nodesQueue.push(currentNode->left);
            level.push(currentLevel);
        }
        if(currentNode->right)
        {
            nodesQueue.push(currentNode->right);
            level.push(currentLevel);
        }
    }
}

int depth(TreeNode* root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return max(depth(root->left), depth(root->right)) + 1;
}
vector<int> rightSideView(TreeNode* root)
{
    int levels = depth(root);
    vector<vector<int> > nodes(levels);
    vector<int> result;
    levelTraversal(root, nodes);
    for(int i=0; i<nodes.size(); ++i)
    {
        int sizeOfCurrentLevel = nodes[i].size();
        result.push_back(nodes[i][sizeOfCurrentLevel-1]);
    }
    return result;
}

