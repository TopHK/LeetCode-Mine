#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int maximalSquare(vector<vector<char> >& matrix) 
{
    if(matrix.empty()) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> temp(cols, 0);
    vector<vector<int> > dp(rows, temp);
    int maxLen = 0;

    for(int j=0; j<cols; ++j)
    {
        if(matrix[0][j] == '1')
        {
            dp[0][j] = 1;
            maxLen = 1;
        }
    }
    for(int i=0; i<rows; ++i)
    {
        if(matrix[i][0] == '1')
        {
            dp[i][0] = 1;
            maxLen = 1;
        }
    }
    for(int i=1; i<rows; ++i)
    {
        for(int j=1; j<cols; ++j)
        {
            if(matrix[i][j] != '0')
            {
                int minValue = min(dp[i-1][j-1], dp[i-1][j]);
                minValue = min(minValue, dp[i][j-1]);
                dp[i][j] = minValue+1;
            }
            if(dp[i][j] > maxLen) maxLen = dp[i][j];
        }
    }
    return maxLen*maxLen;   
}

int main()
{
    int arr[] = {4, 2};
    vector<int> height(arr, arr+sizeof(arr)/sizeof(int));

    return 0;
}
