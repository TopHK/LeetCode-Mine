/*************************************************************************
	> File Name: LongestConsecutiveSequence.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月26日 星期五 14时33分15秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
using namespace std;

int longestConsecutive(vector<int>& nums)
{
    int size = nums.size();
    if(size < 2) return size;

    map<int, bool> numsMap;
    for(int i=0; i<size; ++i) numsMap[nums[i]] = true;
    int start = 0;
    int last = 0; 
    map<int, bool>::iterator pre = numsMap.begin();
    map<int, bool>::iterator it = pre;
    it++;
    int maxLength = 1; 
    int currentIndex = 1;

    while(it != numsMap.end())
    {
        if(pre->first!=INT_MAX && it->first==(pre->first)+1) last++;
        else 
        {
            if(last-start+1 > maxLength) maxLength = last-start+1;
            start = currentIndex;
            last = currentIndex;
        }
        pre = it;
        it++;
    }
    if(last-start+1 > maxLength) maxLength = last-start+1;
    return maxLength;
}

int main()
{
    int arr[] = {5, 100, 4, 200, 6, 1, 3, 2};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    cout<<longestConsecutive(nums)<<endl;

    return 0;
}

