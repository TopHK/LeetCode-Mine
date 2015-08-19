/*************************************************************************
	> File Name: LargestNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月07日 星期二 16时29分11秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

static bool compare(const int& a, const int& b)
{
    char str[30];
    sprintf(str, "%d", a);
    string strA(str);
    sprintf(str, "%d", b);
    string strB(str);
    string strAB = strA+strB;
    string strBA = strB+strA;
    return strAB > strBA;
}

string largestNumber(vector<int>& nums)
{
    string result;
    sort(nums.begin(), nums.end(), compare);
    for(int i=0; i<nums.size(); ++i)
    {
        char str[30];
        sprintf(str, "%d", nums[i]);
        result += string(str);
    }
    size_t pos = result.find_first_not_of('0');
    return pos==string::npos ? "0" : result;
}

int main()
{
    int arr[] = {3, 30, 34, 5, 9};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    cout<<largestNumber(nums)<<endl;

    return 0;
}
