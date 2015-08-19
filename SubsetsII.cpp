/*************************************************************************
	> File Name: Subsets.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月26日 星期五 21时59分57秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
private:
    vector<vector<int> > result;
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> oneResult;
        subsetsCore(nums, 0, oneResult);
        return result;
    }

    void subsetsCore(vector<int>& nums, int start, vector<int>& oneResult)
    {
        if(start == nums.size())
        {
            result.push_back(oneResult);
            return;
        }
        vector<int> anotherResult(oneResult.begin(), oneResult.end());
        anotherResult.push_back(nums[start]);
        if(oneResult.empty() || oneResult[oneResult.size()-1]!=nums[start])
            subsetsCore(nums, start+1, oneResult);
        subsetsCore(nums, start+1, anotherResult);
    }
};

void print(const vector<vector<int> >& result)
{
    for(int i=0; i<result.size(); ++i)
    {
        for(int j=0; j<result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    Solution sol;
    int arr[] = {1, 2, 2};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    vector<vector<int> > result = sol.subsets(nums);

    print(result);
    return 0;
}

