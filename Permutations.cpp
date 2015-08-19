/*************************************************************************
	> File Name: Permutations.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 15时44分18秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void addIntoResult(vector<vector<int> >& result, const vector<int>& nums)
{
    vector<int> temp(nums.begin(), nums.end());
    result.push_back(temp);
}

vector<vector<int> > permute(vector<int>& nums)
{
    vector<vector<int> > result;
    addIntoResult(result, nums);
    while(next_permutation(nums.begin(), nums.end())) addIntoResult(result, nums);
    return result;
}

int main()
{
    int arr[] = {1, 2, 3};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<vector<int> > result = permute(nums);

    for(int i=0; i<result.size(); ++i)
    {
        for(int j=0; j<result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

