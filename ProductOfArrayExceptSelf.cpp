/*************************************************************************
	> File Name: ProductOfArrayExceptSelf.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月16日 星期四 20时34分55秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int size = nums.size();
    vector<int> result(size, 1);
    int product = nums[0];
    for(int i=1; i<size; ++i)
    {
        result[i] = product;
        product *= nums[i];
    }
    product = nums[size-1];
    for(int i=size-2; i>=0; --i)
    {
        result[i] *= product;
        product *= nums[i];
    }
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
    int arr[] = {1, 2, 3, 4};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<int> result = productExceptSelf(nums);
    print(result);

    return 0;
}


