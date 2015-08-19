/*************************************************************************
	> File Name: PermutationII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 20时35分39秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int> > permuteUnique(vector<int>& nums)
{
    vector<vector<int> > result;
    sort(nums.begin(), nums.end());
    result.push_back(nums);

    while(next_permutation(nums.begin(), nums.end()))
        result.push_back(nums);
    return result;
}

int main()
{
    int arr[] = {1, 2, 1};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<vector<int> > result = permuteUnique(nums);
    for(int i=0; i<result.size(); ++i)
    {
        for(int j=0; j<result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
