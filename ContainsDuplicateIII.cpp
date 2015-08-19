/*************************************************************************
	> File Name: ContainsDuplicateIII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月18日 星期六 09时34分52秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

/*
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    int size = nums.size();
    if(nums.empty() || k == 0 || size == 1) return false;
    int maxValue = *max_element(nums.begin(), nums.end());
    int minValue = *min_element(nums.begin(), nums.end());
    if(size < k+1) 
        return (maxValue - minValue <= t);
    multiset<int> arr;
    for(int i = 0; i < size; ++i)
    {
        if(i < k) arr.insert(nums[i]);
        else 
        {
            arr.insert(nums[i]);
            if(*(arr.begin() > t)
                return false;
            arr.erase(arr.find(nums[i - k]));
        }
    }
    return true;
}
*/

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
    int size = nums.size();
    if(size <= 1 || k == 0) return false;

    multiset<long long> arr;
    for(int i = 0; i < size; ++i)
    {
        if(arr.size() == k+1) arr.erase(arr.find(nums[i - k - 1]));
        auto lb = arr.lower_bound(nums[i] - t);
        if(lb != arr.end() && *lb - nums[i] <= t) 
            return true;
        arr.insert(nums[i]);
    }
    return false;
}

int main()
{
    int arr[]  = {1, 3, 1};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    int k = 1;
    int t = 2;
    cout<<containsNearbyAlmostDuplicate(nums, k, t)<<endl;

    return 0;
}

