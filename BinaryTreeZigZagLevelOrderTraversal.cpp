/*************************************************************************
	> File Name: BinaryTreeZigZagLevelOrderTraversal.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月27日 星期六 21时00分07秒
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

class Solution
{
private:
    vector<vector<int> > result;
public:
    void levelOrderCore(vector<TreeNode*> nodes, int level)
    {
        if(nodes.empty()) return;
        int size = nodes.size();
        vector<TreeNode*> nextLevel;
        vector<int> currentLevel;

        for(int i=0; i<size; ++i)
        {
            currentLevel.push_back(nodes[i]->val);
            TreeNode* node = nodes[size-i-1];
            if((level&1) == 0)
            {
                if(node->right) nextLevel.push_back(node->right);
                if(node->left) nextLevel.push_back(node->left);
            }
            if((level&1) != 0)
            {
                if(node->left) nextLevel.push_back(node->left);
                if(node->right) nextLevel.push_back(node->right);
            }
        }
        result.push_back(currentLevel);
        levelOrderCore(nextLevel, level+1);
    }

    vector<vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        if(!root) return result;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        levelOrderCore(nodes, 0);

        return result;
    }
};

