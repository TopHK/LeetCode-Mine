/*************************************************************************
	> File Name: TwoSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月20日 星期六 10时53分35秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct numToIndex
{
    int value;
    int index;
    numToIndex(int v, int i):value(v),index(i){}
};

bool operator<(const numToIndex& a, const numToIndex& b)
{
    return a.value < b.value;
}

vector<int> twoSum(vector<int>& nums, int target)
{

    vector<int> result;
    vector<numToIndex> numsIndex;
    
    // sort by value, meanwhile, keep each values' index 
    for(int i=0; i<nums.size(); ++i)
        numsIndex.push_back(numToIndex(nums[i],i));
    sort(numsIndex.begin(), numsIndex.end());

    int begin = 0;
    int end = numsIndex.size()-1;
    while(begin < end)
    {
        int curSum = numsIndex[begin].value + numsIndex[end].value;
        if(curSum == target)
        {
            result.push_back(numsIndex[begin].index + 1);
            result.push_back(numsIndex[end].index + 1);
            return result;
        }
        else if(curSum > target) end--;
        else begin++;
    }
}

int main()
{
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<int> result;

    result = twoSum(nums, target);
    for(int i=0; i<result.size(); ++i) 
        cout<<result[i]<<" ";
    cout<<endl;

    return 0;
}

