/*************************************************************************
	> File Name: HouseRobber.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 19时12分25秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums)
{
    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);

    int money1 = nums[0];
    int money2 = max(nums[0], nums[1]);
    int currentMoney;
    for(int i=2; i<nums.size(); ++i)
    {
        currentMoney = max(money1+nums[i], money2);
        money1 = money2;
        money2 = currentMoney;
    }
    return currentMoney;
}

