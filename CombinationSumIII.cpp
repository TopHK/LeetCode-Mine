/*************************************************************************
	> File Name: CombinationSumIII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月26日 星期五 12时02分15秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > combinationCore(int start, int k, int n)
{
    vector<vector<int> > result;
    if(k<=0 || n<=0) return result;

    for(int i=start; i<=10-k; ++i)
    {
        if(i < n)
        {
            int firstNum = i;
            vector<vector<int> > currentResult = combinationCore(i+1, k-1, n-i);
            for(int s=0; s<currentResult.size(); ++s)
            {
                vector<int> temp(currentResult[s].begin(), currentResult[s].end());
                temp.insert(temp.begin(),firstNum);
                result.push_back(temp);
            }
        }
        else if(k==1 && i==n)
        {
            vector<int> temp;
            temp.push_back(i);
            result.push_back(temp);
        }
        else break;
    }
    return result;
}

vector<vector<int> > combinationSum3(int k, int n)
{
    return combinationCore(1, k, n) ;
}

int main()
{
    int k = 3;
    int n = 9;
    vector<vector<int> > result = combinationSum3(k, n);

    for(int i=0; i<result.size(); ++i)
    {
        for(int j=0; j<result[i].size(); ++j)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
