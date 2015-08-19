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
using namespace std;

class Solution
{
private:
    set<vector<int> > resultSet;
public:
    /*
    void threeSumCore(vector<int>& nums, int start, int last)
    {
        if(nums.empty() || nums[start]>0 || nums[last]<0 || last-start<2) return;
        int twoSum = nums[start]+nums[last];
        int middle = twoSum*(-1);
        if(find(nums.begin()+start+1, nums.begin()+last, middle) != nums.begin()+last)
        {
            vector<int> oneResult;
            oneResult.push_back(nums[start]);
            oneResult.push_back(middle);
            oneResult.push_back(nums[last]);
            resultSet.insert(oneResult);
        }
        int tempStart = start+1;
        while((nums[tempStart]==nums[start] || nums[tempStart]==middle)&& tempStart<last) tempStart++;
        threeSumCore(nums, tempStart, last);

        int tempLast = last-1;
        while((nums[tempLast]==nums[last] || nums[tempLast]==middle) && tempLast>start) tempLast--;
        threeSumCore(nums, start, tempLast);
    }

    vector<vector<int> > threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        threeSumCore(nums, 0, nums.size()-1);
        vector<vector<int> > result(resultSet.begin(), resultSet.end());
        return result;
    }
    */

    vector<vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > result;
        int size = nums.size();
        if(size < 3) return result;

        sort(nums.begin(), nums.end());
        for(int i=0; (i<=size-3)&&(nums[i]<=0); ++i)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int twoSum = 0-nums[i];
            int start = i+1;
            int last = size-1;

            while(start < last)
            {
                int twoSumTemp = nums[start]+nums[last];
                if(twoSum == twoSumTemp)
                {
                    vector<int> oneResult;
                    oneResult.push_back(nums[i]);
                    oneResult.push_back(nums[start]);
                    oneResult.push_back(nums[last]);
                    result.push_back(oneResult);
                    start++; 
                    while(start<last && nums[start]==nums[start-1]) start++;
                    last--; 
                    while(start<last && nums[last]==nums[last+1]) last--; 
                }
                else if(twoSum > twoSumTemp) start++; 
                else last--; 
            }
        }
        return result;
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
    int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    Solution sol;
    vector<vector<int> > result = sol.threeSum(nums);
    print(result);

    return 0;
}

