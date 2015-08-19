/*************************************************************************
	> File Name: MinimumSizeSubarraySum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月01日 星期三 11时56分35秒
 ************************************************************************/

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

/* Solution 1: o(n)
int minSubArrayLen(int s, vector<int>& nums)
{
    if(nums.empty()) return 0;
    int size = nums.size();
    int start = 0;
    int last = 0;
    int minLen = INT_MAX;
    int sum = 0;

    while(start<=last && last<=size)
    {
        while(last<=size && sum<s)
            sum += nums[last++];
        while(start<=last && last<=size && sum>=s)
        {
            minLen = min(minLen, last-start);
            sum -= nums[start++];
        }
    }
    return (minLen==INT_MAX ? 0 : minLen);
}
*/

// Solution 2: o(nlogn)
int binarySearch(int start, int last, int target, const vector<int>& sums)
{
    while(start <= last)
    {
        int middle = start+((last-start)>>1);
        if(sums[middle] >= target) last = middle-1;
        else start = middle+1;
    }
    return start;
}
int minSubArrayLen(int s, vector<int>& nums)
{
    if(nums.empty()) return 0;
    int size = nums.size();
    int start = 0;
    int last = 0;
    int minLen = size+1;
    vector<int> sums(size+1, 0);
    sums[0] = 0;

    for(int i=1; i<=size; ++i) sums[i] = sums[i-1]+nums[i-1];
    for(int i=0; i<size; ++i)
    {
        int right = binarySearch(i+1, size, sums[i]+s, sums);
        if(right == size+1) break;
        minLen = min(minLen, right-i);
    }
    return (minLen==size+1 ? 0 : minLen);
}

int main()
{
    int arr[] = {2, 3, 1, 2, 4, 3};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    int s = 7;
    cout<<minSubArrayLen(s, nums)<<endl;

    return 0;
}

