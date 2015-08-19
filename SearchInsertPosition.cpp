/*************************************************************************
	> File Name: SearchInsertPosition.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 15时10分50秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int size = nums.size();
    int left = 0;
    int right = size-1;

    while(left <= right)
    {
        int middle = left+((right-left)>>1);
        if(target < nums[middle]) right = middle-1;
        else if(target > nums[middle]) left = middle+1;
        else return middle;
    }
    if(right == -1) return 0;
    else return left;
}

int main()
{
    int arr[] = {1, 3, 5, 6};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    int target = 0;
    cout<<searchInsert(nums,target)<<endl;

    return 0;
}

