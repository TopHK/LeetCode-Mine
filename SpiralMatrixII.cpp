/*************************************************************************
	> File Name: SpiralMatrixII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月24日 星期三 22时07分02秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void setCircle(vector<vector<int> >& matrix, int& start, int row, int col, int length)
{
    int iMin = row;
    int iMax = row+length-1;
    int jMin = col;
    int jMax = col+length-1;

    for(int j = jMin; j<=jMax; ++j) matrix[iMin][j] = start++;
    for(int i = iMin+1; i<=iMax; ++i) matrix[i][jMax] = start++;
    for(int j = jMax-1; j>=jMin; --j) matrix[iMax][j] = start++;
    for(int i = iMax-1; i>=iMin+1; --i) matrix[i][jMin] = start++;
}

vector<vector<int> > generateMatrix(int n)
{
    vector<vector<int> > result;
    for(int i=0; i<n; ++i)
    {
        vector<int> temp(n);
        result.push_back(temp);
    }

    int row = 0;
    int col = 0;
    int start = 1;
    while(n >= 1)
    {
        setCircle(result, start, row, col, n);
        row++;
        col++;
        n -= 2;
    }
    return result;
}

void print(const vector<vector<int> >& matrix)
{
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=0; j<matrix[0].size(); ++j)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n = 4;
    vector<vector<int> > matrix = generateMatrix(n);
    print(matrix);

    return 0;
}

