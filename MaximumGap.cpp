/*************************************************************************
	> File Name: MaximumGap.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月22日 星期一 15时46分23秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;

int maximumGap(vector<int>& nums)
{
    if(nums.size() < 2) return 0;
    sort(nums.begin(), nums.end());
    int maxGap = abs(nums[1]-nums[0]);

    for(int i=2; i<nums.size(); ++i)
    {
        int tempGap = abs(nums[i]-nums[i-1]);
        if(tempGap > maxGap) maxGap = tempGap;
    }    
    return maxGap;
}

int main()
{
    int arr[] = {3, 8, 4, 6, 5, 1, 2};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    cout<<maximumGap(nums)<<endl;

    return 0;
}


