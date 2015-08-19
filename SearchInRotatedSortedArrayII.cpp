/*************************************************************************
	> File Name: SearchInRotatedSortedArrayII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月25日 星期四 10时26分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool search(vector<int>& nums, int target)
{
    if(nums.empty()) return false;
    int size = nums.size();
    int begin = 0;
    int end = size-1;
    int middle;

    while(begin <= end)
    {
        middle = begin+((end-begin)>>1);
        if(nums[middle] != nums[begin])
        {
            if(target > nums[middle]) begin = middle+1;
            else if(target < nums[middle]) end = middle-1;
            else return true;
        }
        else if(find(nums.begin(), nums.end(), target) != nums.end()) return true;
        else return false;
    }
    return false;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    vector<int> nums1(arr1, arr1+sizeof(arr1)/sizeof(int));
    if(search(nums1, 1)) cout<<"Yes!"<<endl;
    else cout<<"No!"<<endl;
    int arr2[] = {2, 3, 4, 5, 1};
    vector<int> nums2(arr2, arr2+sizeof(arr2)/sizeof(int));
    if(search(nums2, 5)) cout<<"Yes!"<<endl;
    else cout<<"No!"<<endl;
    int arr3[] = {1, 1, 2, 3, 3, 4, 5};
    vector<int> nums3(arr3, arr3+sizeof(arr3)/sizeof(int));
    if(search(nums3, 1)) cout<<"Yes!"<<endl;
    else cout<<"No!"<<endl;
    int arr4[] = {1, 1, 1, 2, 3, 0, 0};
    vector<int> nums4(arr4, arr4+sizeof(arr4)/sizeof(int));
    if(search(nums4, 5)) cout<<"Yes!"<<endl;
    else cout<<"No!"<<endl;

    return 0;
}
