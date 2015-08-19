/*************************************************************************
	> File Name: 4Sum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月06日 星期一 09时48分16秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target)
{
    vector<vector<int> > result;
    int size = nums.size();
    if(size < 4) return result;
    sort(nums.begin(), nums.end());
    for(int i=0; i<=size-4; ++i)
    {
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<=size-3; ++j)
        {
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int restSum = target-(nums[i]+nums[j]);
            int left = j+1;
            int right = size-1;
            while(left < right)
            {
                int tempSum = nums[left]+nums[right];
                if(tempSum == restSum)
                {
                    vector<int> oneResult;
                    oneResult.push_back(nums[i]);
                    oneResult.push_back(nums[j]);
                    oneResult.push_back(nums[left]);
                    oneResult.push_back(nums[right]);
                    result.push_back(oneResult);
                    while(left<right && nums[left+1]==nums[left]) left++;
                    while(left<right && nums[right-1]==nums[right]) right--; 
                    left++;
                    right--;
                }
                else if(tempSum > restSum) right--;
                else left++;
            }
        }
    }
    return result;
}

void print(const vector<vector<int> >& nums)
{
    for(int i=0; i<nums.size(); ++i)
    {
        for(int j=0; j<nums[0].size(); ++j)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int arr[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<vector<int> > result = fourSum(nums, target);
    print(result);
    cout<<result.size()<<endl;

    return 0;
}
