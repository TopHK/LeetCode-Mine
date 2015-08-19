/*************************************************************************
	> File Name: CombinationSumIII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月26日 星期五 12时02分15秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > combinationCore(vector<int>& nums, int start, int target)
{
    vector<vector<int> > result;
    if(nums.empty() || target==0) return result;

    for(int i=start; i<nums.size(); ++i)
    {
        if(nums[i] < target)
        {
            int firstNum = nums[i];
            vector<vector<int> > currentResult = combinationCore(nums, i, target-firstNum);
            for(int s=0; s<currentResult.size(); ++s)
            {
                vector<int> temp(currentResult[s].begin(), currentResult[s].end());
                temp.insert(temp.begin(),firstNum);
                result.push_back(temp);
            }
        }
        else if(nums[i] == target)
        {
            vector<int> temp;
            temp.push_back(nums[i]);
            result.push_back(temp);
        }
        else break;
    }
    return result;
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    return combinationCore(candidates, 0, target) ;
}

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
    int arr[] = {8, 7, 4, 3};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    
    int target = 11;
    vector<vector<int> > result = combinationSum(nums, target);
    print(result);
    return 0;
}
