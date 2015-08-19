/*************************************************************************
	> File Name: NextPermutation.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月29日 星期一 12时28分18秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    int size = nums.size();
    if(size < 2) return;
    int i = size-2;
    while(i>=0 && nums[i]>=nums[i+1]) i--;
    if(i < 0)
    {
        sort(nums.begin(), nums.end());
        return;
    }
    int j = size-1;
    while(j>=0 && nums[j]<=nums[i]) j--;
    swap(nums[i], nums[j]);
    sort(nums.begin()+i+1, nums.end());
}

void print(const vector<int>& nums)
{
    for(int i=0; i<nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {3, 2, 1};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    nextPermutation(nums);
    print(nums);
    return 0;
}

