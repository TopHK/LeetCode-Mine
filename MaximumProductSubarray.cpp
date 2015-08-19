/*************************************************************************
	> File Name: MaximumProductSubarray.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月07日 星期二 09时18分53秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/*
int maxProduct(vector<int>& nums)
{
    if(nums.empty()) return 0;
    int result = nums[0];
    int currentMax = nums[0];
    int accumulateValue = nums[0];
    int size = nums.size();
    for(int i=1; i<size; ++i)
    {
        accumulateValue *= nums[i];
//        if(currentMax*nums[i] > nums[i]) currentMax *= nums[i];
//        else currentMax = nums[i];
        currentMax = max(currentMax*nums[i], nums[i]);
        currentMax = max(currentMax, nums[i]*nums[i-1]);
        int maxValue = max(accumulateValue, currentMax);
        if(maxValue > result) result = maxValue;
    }
    return result;
}
*/

int maxProduct(vector<int>& nums)
{
    if(nums.empty()) return 0;
    int result = nums[0];
    int currentMax = nums[0];
    int currentMin = nums[0];
    int size = nums.size();

    for(int i=1; i<size; ++i)
    {
        int tempMax = currentMax;
        currentMax = max(tempMax*nums[i], nums[i]);
        currentMax = max(currentMax, currentMin*nums[i]);
        currentMin = min(currentMin*nums[i], nums[i]);
        currentMin = min(currentMin, tempMax*nums[i]);
        if(currentMax > result) result = currentMax;
    }
    return result;
}

int main()
{
    int arr[] = {2, 3, -2, 4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    cout<<maxProduct(nums)<<endl;

    return 0;
}

