/*************************************************************************
	> File Name: CombinationSumII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月29日 星期一 09时54分54秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int> > result;
    vector<int> path;
public:
    void combinationSum2Core(vector<int>& candidates, int target, int start, int currentSum, vector<int>& oneResult)
    {
        if(start == candidates.size()) return;
        int tempSum = currentSum+candidates[start];
        if(tempSum == target)
        {
            oneResult.push_back(candidates[start]);
            result.push_back(oneResult);
            return;
        }
        else if(tempSum < target)
        {
//            if(oneResult.empty() || candidates[start]!=oneResult[oneResult.size()-1]) 
//                combinationSum2Core(candidates, target, start+1, currentSum, oneResult);               
            vector<int> tempResult(oneResult.begin(), oneResult.end());
            tempResult.push_back(candidates[start]);
            combinationSum2Core(candidates, target, start+1, tempSum, tempResult);
        }
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        if(candidates.empty())  return result;
        vector<int> oneResult;
        int currentSum = 0;
        
        sort(candidates.begin(), candidates.end());
        combinationSum2Core(candidates, target, 0, currentSum, oneResult);
        return result;
    }
    /*
    void combinationSum2Core(vector<int>& candidates, int target, int start)
    {
        if(target < 0) return;
        if(start == candidates.size())
        {
            if(target == 0) result.push_back(path);
            return;
        }
        if(path.empty() || candidates[start]!=path[path.size()-1])
            combinationSum2Core(candidates, target, start+1);
        path.push_back(candidates[start]);
        combinationSum2Core(candidates, target-candidates[start], start+1);
        path.pop_back();
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        if(candidates.empty() || target<=0)  return result;
        sort(candidates.begin(), candidates.end());
        combinationSum2Core(candidates, target, 0);
        return result;
    }
    */
};

void print(const vector<vector<int> >& result)
{
    for(int i=0; i<result.size(); ++i)
    {
        for(int j=0; j<result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates(arr, arr+sizeof(arr)/sizeof(int));
    int target = 8;
    Solution sol;
    vector<vector<int> > result = sol.combinationSum2(candidates, target);
    print(result);

    return 0;
}
