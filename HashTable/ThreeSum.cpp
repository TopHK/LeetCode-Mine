/*************************************************************************
	> File Name: ThreeSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月20日 星期六 15时18分51秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// using binary search to find the rest value (restValue = 0-(nums[begin]+nums[end]))
bool findRestValue(const vector<int>& nums, const int& begin, const int& end, const int& restValue, int& range)
{
    // range=-1:locate the left of begin
    // range=0 :locate in the range of [begin, end]
    // range=1 :locate the right of end 
    int left = begin;
    int right = end;
    while(left <= right)
    {
        int middle = left+((right-left)>>1);
        if(nums[middle] == restValue)
        {
            range = 0;
            return true;
        }
        else if(nums[middle] > restValue) right = middle-1;
        else left = middle+1;
    }

    if(right == begin-1) range = -1;
    else if(left == end+1) range = 1;
    else range = 0; 
    return false;
}

// add a triplet to the result vector
void addResult(vector<vector<int> >& result, const int& beginValue, const int& restValue, const int& endValue)
{
    vector<int> temp;
    temp.push_back(beginValue);
    temp.push_back(restValue);
    temp.push_back(endValue);
    result.push_back(temp);
}


vector<vector<int> > result;
int negaIndex = -1;
int posiIndex = -1;
bool zeroExist = false;

vector<vector<int> > threeSum(vector<int>& nums)
{
    if(nums.size() < 3) return result;
    sort(nums.begin(), nums.end());

    // find the max negative number and the min positive number

    for(int i=1; i<nums.size(); ++i)
    {
        if(0 == nums[i]) zeroExist = true;
        if(nums[i-1]<0 && nums[i]>=0) negaIndex = i-1;
        if(nums[i-1]<=0 && nums[i]>0)
        {
            posiIndex = i;
            break;
        }
    }
    
    int begin = 0;
    int end = nums.size()-1;
    int restValue;
    int range;
    bool found;
    while(end-begin>=2 && nums[begin]<=0 && nums[end]>=0)
    {
        restValue = 0-(nums[begin]+nums[end]);
        if(restValue == 0)
        {
            if(zeroExist) addResult(result, nums[begin], 0, nums[end]);
            begin++;
        }
        else if(restValue > 0)
            found = findRestValue(nums, posiIndex, end-1, restValue, range);
        else
            found = findRestValue(nums, begin+1, negaIndex, restValue, range);

        if(found) 
        {
            addResult(result, nums[begin], restValue, nums[end]);   
            begin++;
            found = false;
        }
        else 
        {
            if(range == -1) end--;
            else begin++;
        }
    }
}

void threeSumCore(const vector<int>& nums, int begin, int end)
{
    int restValue;
    int range;
    bool found;
    if(end-begin>=2 && nums[begin]<=0 && nums[end]>=0)
    {
        restValue = 0-(nums[begin]+nums[end]);
        if(restValue == 0)
        {
            if(zeroExist) addResult(result, nums[begin], 0, nums[end]);
            begin++;
        }
        else if(restValue > 0)
            found = findRestValue(nums, posiIndex, end-1, restValue, range);
        else
            found = findRestValue(nums, begin+1, negaIndex, restValue, range);

        if(found) 
        {
            addResult(result, nums[begin], restValue, nums[end]);   
            begin++;
            found = false;
        }
        else 
        {
            if(range == -1) end--;
            else begin++;
        }
    }
}

void print(const vector<vector<int> >& nums)
{
    for(int i=0; i<nums.size(); ++i)
    {
        for(int j=0; j<nums.size(); ++j)
            cout<<nums[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<vector<int> > result;

    result = threeSum(nums);
    cout<<result.size()<<endl;
    cout<<result[0].size()<<endl;
    print(result);

    return 0;
}
