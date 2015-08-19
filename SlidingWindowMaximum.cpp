/*************************************************************************
	> File Name: SlidingWindowMaximum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月20日 星期一 11时11分42秒
 ************************************************************************/

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> result;
    deque<int> buffer;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(!buffer.empty() && buffer.front() <= i - k)
            buffer.pop_front();
        while(!buffer.empty() && nums[buffer.back()] <= nums[i])
            buffer.pop_back();
        buffer.push_back(i);
        if(i >= k - 1)
            result.push_back(nums[buffer.front()]);
    }
}

