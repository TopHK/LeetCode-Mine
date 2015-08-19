/*************************************************************************
	> File Name: FindPeakElement.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 08时41分18秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums)
{
    int size = nums.size();
    if(1 == size) return 0;
    for(int i=0; i<size; ++i)
    {
        if(0==i && nums[i]>nums[i+1]) return 0;
        if(size-1==i && nums[i]>nums[i-1]) return size-1;
        if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 1};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    cout<<findPeakElement(nums)<<endl;

    return 0;
}


