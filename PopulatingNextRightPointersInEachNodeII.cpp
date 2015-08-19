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

void connect(TreeLinkNode* root)
{
    if(!root || !root->left&&!root->right) return;
    TreeLinkNode* currentLeftNode = root;
    while(currentLeftNode)
    {
        TreeLinkNode* levelNode = currentLeftNode;
        TreeLinkNode* firstNode = NULL;
        TreeLinkNode* lastNode = NULL;
        bool isFirstNode = true;

        while(levelNode)
        {
            if(levelNode->left)
            {
                if(isFirstNode) 
                {
                    firstNode = levelNode->left;
                    lastNode = firstNode;
                    isFirstNode = false;
                }
                else 
                {
                    lastNode->next = levelNode->left;
                    lastNode = lastNode->next;
                }
            }
            if(levelNode->right)
            {
                if(isFirstNode) 
                {
                    firstNode = levelNode->right;
                    lastNode = firstNode;
                    isFirstNode = false;
                }
                else 
                {
                    lastNode->next = levelNode->right;
                    lastNode = lastNode->next;
                }
            }
            levelNode = levelNode->next;
        }
        if(!firstNode) return;
        currentLeftNode = firstNode;
    }
}
