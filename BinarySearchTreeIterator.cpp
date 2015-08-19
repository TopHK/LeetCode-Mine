/*************************************************************************
	> File Name: BinarySearchTreeIterator.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 20时34分56秒
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

class BSTIterator
{
private:
    vector<int> result;
    int nextIndex;
public:
    void InOrderTraversal(TreeNode* root)
    {
        if(!root) return;
        InOrderTraversal(root->left);
        result.push_back(root->val);
        InOrderTraversal(root->right);
    }

    BSTIterator(TreeNode* root)
    {
        nextIndex = 0;
        if(root) InOrderTraversal(root);
    }

    bool hasNext()
    {
        if(result.empty()) return false;
        if(nextIndex >= result.size()) return false;
        else return true;
    }

    int next()
    {
        return result[nextIndex++];
    }
};

