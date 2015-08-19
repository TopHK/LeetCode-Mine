/*************************************************************************
	> File Name: JumpGameII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月29日 星期一 19时48分06秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

/*
int jump(vector<int>& nums)
{
    int size = nums.size();
    vector<int> maxJump(nums.size(), 0);
    if(nums[0] == size-1) return 1;
    maxJump[0] = nums[0];

    for(int i=1; i<size-1; ++i)
        maxJump[i] = max(maxJump[i-1]-1, nums[i]);
    int end = size-1;
    int step = 0;
    for(int i=0; i<end; ++i)
    {
        if(maxJump[i] >= end-i)
        {
            step++;
            end = i;
            i = -1;
        }
    }
    return step;
}
*/

int jump(vector<int>& nums)
{
    int step = 0;
    int currentPos = 0;
    int maxPos = 0;

    for(int i=0; i<nums.size(); ++i)
    {
        if(currentPos < i)
        {
            step++;
            currentPos = maxPos;
        }
        maxPos = max(maxPos, i+nums[i]);
    }
    return step;
}
