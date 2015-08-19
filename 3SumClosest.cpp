/*************************************************************************
	> File Name: 3Sum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月27日 星期六 09时52分43秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstdlib>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        int cloestSum = nums[0]+nums[1]+nums[2];
        for(int i=0; i<=size-3; ++i)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int twoSum = target-nums[i];
            int twoSumCloest = nums[i+1]+nums[i+2]; 
            int start = i+1;
            int last = size-1;

            while(start < last)
            {
                int twoSumTemp = nums[start]+nums[last];
                if(twoSum == twoSumTemp) return target;
                else if(twoSum > twoSumTemp) 
                {
                    if(abs(twoSumTemp-twoSum) < abs(twoSumCloest-twoSum)) twoSumCloest = twoSumTemp;
                    start++;    
                }
                else
                {
                    if(abs(twoSumTemp-twoSum) < abs(twoSumCloest-twoSum)) twoSumCloest = twoSumTemp;
                    last--;    
                }
            }
            int threeSumTemp = nums[i] + twoSumCloest;
            if(abs(threeSumTemp-target) < abs(cloestSum-target)) cloestSum = threeSumTemp;
        }
        return cloestSum;
    }
};

void print(const vector<vector<int> >& nums)
{
    for(int i=0; i<nums.size(); ++i)
    {
        for(int j=0; j<nums[i].size(); ++j)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int arr[] = {-1, 2, 1, -4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    Solution sol;
    int target = 1;
    cout<<sol.threeSumClosest(nums, target)<<endl;

    return 0;
}

