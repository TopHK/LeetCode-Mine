/*************************************************************************
	> File Name: PathSumII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月27日 星期六 16时41分27秒
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
    void pathSumCore(TreeNode* root, vector<int>& onePath, int& currentSum, const int sum)
    {
        if(!root) return;
        int rootValue = root->val;
        if(!root->left && !root->right)
        {
            if(currentSum+rootValue == sum) 
            {
                onePath.push_back(rootValue);
                result.push_back(onePath);
            }
            return;
        }
        onePath.push_back(rootValue);
        currentSum += rootValue;
        int currentSumLeft = currentSum;
        vector<int> onePathLeft(onePath.begin(), onePath.end());
        pathSumCore(root->left, onePathLeft, currentSumLeft, sum);
        int currentSumRight = currentSum;
        vector<int> onePathRight(onePath.begin(), onePath.end());
        pathSumCore(root->right, onePathRight, currentSumRight, sum);
//        if(currentSum+rootValue < sum)
//        {
//            onePath.push_back(rootValue);
//            currentSum += rootValue;
//            int currentSumLeft = currentSum;
//            vector<int> onePathLeft(onePath.begin(), onePath.end());
//            pathSumCore(root->left, onePathLeft, currentSumLeft, sum);
//            int currentSumRight = currentSum;
//            vector<int> onePathRight(onePath.begin(), onePath.end());
//            pathSumCore(root->right, onePathRight, currentSumRight, sum);
//        }
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
        int currentSum = 0;
        vector<int> onePath;
        pathSumCore(root, onePath, currentSum, sum);
        return result;
    }
};

