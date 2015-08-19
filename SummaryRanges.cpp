/*************************************************************************
	> File Name: SummaryRanges.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月26日 星期五 11时30分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
#include<cstdio>
using namespace std;

string transferToRange(const vector<int>& nums, const int begin, const int end)
{
    string range;
    char tempCtr[50];
    sprintf(tempCtr, "%d", nums[begin]);
    string tempStr(tempCtr);
    range += tempStr; 
    if(end > begin) 
    {
        range += "->";
        sprintf(tempCtr, "%d", nums[end]);
        tempStr = tempCtr;
        range += tempStr; 
    }
    return range;
}

vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> result;
    if(nums.empty()) return result;
     
    int begin = 0;
    int end = 0;
    int lastValue = INT_MIN;
    nums.insert(nums.end(), lastValue);
    for(int i=1; i<nums.size(); ++i)
    {
        if(nums[i]==nums[i-1]+1 && nums[i-1]!=INT_MAX) end++;
        else 
        {
            string oneRange = transferToRange(nums, begin, end);
            result.push_back(oneRange);
            begin = i;
            end = i;
        }
    }

    return result;
}

int main()
{
    int arr[] = {0,1,2,4,5,7};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<string> result = summaryRanges(nums);

    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<endl;
    return 0;
}
