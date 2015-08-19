/*************************************************************************
	> File Name: SearchForARange.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 20时20分26秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int lowerBound(const vector<int>& nums, int target)
{
    int size = nums.size();
    int begin = 0;
    int end = size-1;
    int middle;

    while(begin <= end)
    {
        middle = begin+((end-begin)>>1);
        if(nums[middle] == target)
        {
            if(middle==0 || nums[middle-1]!=target) return middle;
            else end = middle-1;
        }
        else if(nums[middle] > target) end = middle-1;
        else begin = middle+1;
    }
    return -1;
}

int upperBound(const vector<int>& nums, int target)
{
    int size = nums.size();
    int begin = 0;
    int end = size-1;
    int middle;

    while(begin <= end)
    {
        middle = begin+((end-begin)>>1);
        if(nums[middle] == target)
        {
            if(middle==size-1 || nums[middle+1]!=target) return middle;
            else begin = middle+1;
        }
        else if(nums[middle] > target) end = middle-1;
        else begin = middle+1;
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> result;
    result.push_back(lowerBound(nums, target));
    result.push_back(upperBound(nums, target));
    return result;
}

int main()
{
    int arr[] = {5, 7, 7, 8, 8, 10};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    int target = 8;
    vector<int> result = searchRange(nums, target);
    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;

    return 0;
}
