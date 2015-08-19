/*************************************************************************
	> File Name: MinimumPathSum.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 21时06分21秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int> >& grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    for(int j=1; j<cols; ++j) grid[0][j] += grid[0][j-1];
    for(int i=1; i<rows; ++i) grid[i][0] += grid[i-1][0];

    for(int i=1; i<rows; ++i)
    {
        for(int j=1; j<cols; ++j)
            grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
    }
    return grid[rows-1][cols-1];
}

