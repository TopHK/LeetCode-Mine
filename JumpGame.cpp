/*************************************************************************
	> File Name: JumpGame.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月26日 星期五 22时26分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool canJump(vector<int>& nums)
{
    int size = nums.size();
    if(size < 2) return true;

    int maxStep = nums[0];
    for(int i=1; i<nums.size(); ++i)
    {
        if(maxStep > 0)
            maxStep = max(--maxStep, nums[i]);
        else return false;
    }
    return true;
}

int main()
{
    int arr1[] = {2, 3, 1, 1, 4};
    vector<int> nums1(arr1, arr1+sizeof(arr1)/sizeof(int));
    int arr2[] = {3, 2, 1, 0, 4};
    vector<int> nums2(arr2, arr2+sizeof(arr2)/sizeof(int));

    if(canJump(nums1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    if(canJump(nums2)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
