/*************************************************************************
	> File Name: MajorityElementsII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月01日 星期三 21时41分24秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
    vector<int> result;
    if(nums.empty()) return result;
    int size = nums.size();
    int candidate1;
    int count1 = 0;
    int candidate2;
    int count2 = 0;

    for(int i=0; i<nums.size(); ++i)
    {
        if(count1==0 || candidate1==nums[i])
        {
            count1++;
            candidate1 = nums[i];
        }
        else if(count2==0 || candidate2==nums[i])
        {
            count2++;
            candidate2 = nums[i];
        }
        else 
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    for(int i=0; i<size; ++i)
    {
        if(nums[i] == candidate1) count1++;
        else if(nums[i] == candidate2) count2++;
    }
    if(count1 > size/3) result.push_back(candidate1);
    if(count2 > size/3) result.push_back(candidate2);

    return result;
}

void print(const vector<int>& nums)
{
    for(int i=0; i<nums.size(); ++i)
        cout<<nums[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {9, 3, 7, 2, 3, 3};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<int> result = majorityElement(nums);
    print(result);

    return 0;
}
