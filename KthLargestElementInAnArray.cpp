/*************************************************************************
	> File Name: KthLargestElementInAnArray.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 16时11分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& nums, int begin, int end)
{
    while(begin < end)
    {
        int pivot = nums[begin];
        while(begin<end && nums[end]>=pivot) end--;
        if(begin < end) nums[begin++] = nums[end];
        while(begin<end && nums[begin]<pivot) begin++;
        if(begin < end) nums[end--] = nums[begin];
        nums[begin] = pivot;
    }
    return begin;
}

int findKthLargest(vector<int>& nums, int k)
{
    int size = nums.size();
    int begin = 0;
    int end = size-1;
    int position = partition(nums, begin, end);
    while(position != size-k)
    {
        if(position < size-k) begin = position+1;
        else end = position-1;
        position = partition(nums, begin, end);
        cout<<position<<endl;
    }

    return nums[size-k];
}

int main()
{
    int arr[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    int k = 9;

    cout<<findKthLargest(nums, k)<<endl;
    return 0;
}
