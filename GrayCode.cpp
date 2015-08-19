/*************************************************************************
	> File Name: GrayCode.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 13时18分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> grayCode(int n)
{
    vector<int> result;
    int currentNum = 0;
    result.push_back(0);
    int temp = currentNum;

    for(int i=0; i<n; ++i)
    {
        int mask = 1<<i;
        temp = currentNum ^ mask;
        if(find(result.begin(), result.end(), temp) == result.end())
        {
            result.push_back(temp);
            currentNum = temp;
            i = -1;
        }
    }
    return result;
}

int main()
{
    int n = 2;
    vector<int> result = grayCode(n);
    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<" ";
    cout<<endl;

    return 0;
}
