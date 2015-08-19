/*************************************************************************
	> File Name: BinaryTreeLevelOrderTraversalII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月25日 星期四 10时57分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > levelOrderBottom(TreeNode* root)
{
    vector<vector<int> > result;
    if(!root) return result;
    TreeNode* currentNode = root;
    int currentLevel = 0;
    queue<TreeNode* > nodesQueue;
    nodesQueue.push(root);
    queue<int> levelQueue;
    levelQueue.push(0);

    while(!nodesQueue.empty())
    {
        currentNode = nodesQueue.front();
        nodesQueue.pop();
        currentLevel = levelQueue.front();
        levelQueue.pop();
        if(currentLevel >= result.size())
        {
            vector<int> temp;
            result.push_back(temp);
        }
        result[currentLevel++].push_back(currentNode->val);

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
    int sizeOfResult = result.size();
    for(int i=0; i<(sizeOfResult>>1); ++i) result[i].swap(result[sizeOfResult-i-1]);
    return result;
}

