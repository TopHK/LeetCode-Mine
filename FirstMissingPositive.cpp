/*************************************************************************
	> File Name: FirstMissingPositive.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月02日 星期四 10时22分44秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    if(nums.empty()) return 1;
    int size = nums.size();

    for(int i=0; i<size; ++i)
    {
        while(nums[i]>0 && nums[i]!=i+1 && nums[i]<=size)
        {
            int tempValue = nums[nums[i]-1];
            if(tempValue == nums[i]) break;
            nums[nums[i]-1] = nums[i];
            nums[i] = tempValue;
        }
    }
    for(int i=0; i<size; ++i)
        if(nums[i] != i+1) return i+1;
    return size+1;
}

