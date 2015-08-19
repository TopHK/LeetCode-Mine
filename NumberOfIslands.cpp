/*************************************************************************
	> File Name: NumberOfIslands.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月03日 星期五 16时11分54秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

/*
int numIslands(vector<vector<char> >& grid)
{
    if(grid.empty()) return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int> > gridCopy;
    for(int i=0; i<=rows+1; ++i)
    {
        vector<int> temp(cols+2, 0);
        if(i==0 || i==rows+1) 
        {
            gridCopy.push_back(temp);
            continue;
        }
        for(int j=1; j<=cols; ++j)
            temp[j] = grid[i-1][j-1] - '0';
        gridCopy.push_back(temp);
    }
    int count = 2;
    for(int i=1; i<=rows; ++i)
    {
        for(int j=1; j<=cols; ++j)
        {
            if(gridCopy[i][j] == 0) continue;
            if(gridCopy[i][j] > 1)
            {
                if(gridCopy[i][j+1] == 1) gridCopy[i][j+1] = gridCopy[i][j];
                if(gridCopy[i+1][j] == 1) gridCopy[i+1][j] = gridCopy[i][j];
            }
            if(gridCopy[i][j] == 1)
            {
                int maxValue = max(gridCopy[i][j-1], gridCopy[i-1][j]);
                maxValue = max(maxValue, gridCopy[i][j+1]);
                if(maxValue <= 1) 
                {
                    gridCopy[i][j] = count++;
                    if(gridCopy[i][j+1] == 1) gridCopy[i][j+1] = gridCopy[i][j];
                    if(gridCopy[i+1][j] == 1) gridCopy[i+1][j] = gridCopy[i][j];
                }
                else gridCopy[i][j] = maxValue;
            }
        }
    }
    return count-2;
}
*/

/*
int numIslands(vector<vector<char> >& grid)
{
    if(grid.empty()) return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    map<pair<int,int>, bool> lands;
    queue<pair<int, int> > landsQueue;
    int count = 0;
    
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
            if(grid[i][j] == '1') lands[make_pair(i,j)] = true;
    }

//    while(!lands.empty())
//    {
//        map<pair<int,int>, bool>::iterator it = lands.begin();
//        landsQueue.push(it->first);
//        count++;
//        while(!landsQueue.empty())
//        {
//            pair<int, int> currentLand = landsQueue.front();
//            landsQueue.pop();
//            lands.erase(currentLand);
//            int row = currentLand.first;
//            int col = currentLand.second;
//            if(row>0 && grid[row-1][col]=='1' && lands.find(make_pair(row-1, col))!=lands.end())
//                landsQueue.push(make_pair(row-1, col));
//            if(row<rows-1 && grid[row+1][col]=='1' && lands.find(make_pair(row+1, col))!=lands.end())
//                landsQueue.push(make_pair(row+1, col));
//            if(col>0 && grid[row][col-1]=='1' && lands.find(make_pair(row, col-1))!=lands.end())
//                landsQueue.push(make_pair(row, col-1));
//            if(col<cols-1 && grid[row][col+1]=='1' && lands.find(make_pair(row, col+1))!=lands.end())
//                landsQueue.push(make_pair(row, col+1));
//        }
//    }
    while(!lands.empty())
    {
        map<pair<int,int>, bool>::iterator it = lands.begin();
        lands.erase(it);
        landsQueue.push(it->first);
        count++;
        while(!landsQueue.empty())
        {
            pair<int, int> currentLand = landsQueue.front();
            landsQueue.pop();
            lands.erase(currentLand);
            int row = currentLand.first;
            int col = currentLand.second;
            if(row>0 && grid[row-1][col]=='1' && lands.find(make_pair(row-1, col))!=lands.end())
            {
                lands.erase(make_pair(row-1, col));
                landsQueue.push(make_pair(row-1, col));
            }
            if(row<rows-1 && grid[row+1][col]=='1' && lands.find(make_pair(row+1, col))!=lands.end())
            {
                lands.erase(make_pair(row+1, col));
                landsQueue.push(make_pair(row+1, col));
            }
            if(col>0 && grid[row][col-1]=='1' && lands.find(make_pair(row, col-1))!=lands.end())
            {
                lands.erase(make_pair(row, col-1));
                landsQueue.push(make_pair(row, col-1));
            }
            if(col<cols-1 && grid[row][col+1]=='1' && lands.find(make_pair(row, col+1))!=lands.end())
            {
                lands.erase(make_pair(row, col+1));
                landsQueue.push(make_pair(row, col+1));
            }
        }
    }
    return count;
}
*/

// Solution 2, dfs
void numIslandsCore(vector<vector<char> >& grid, const int& rows, const int& cols, int row, int col)
{
    if(row<0 || row>=rows || col<0 || col>=cols) return;
    if(grid[row][col] == '1')
    {
        grid[row][col] = 2;
        numIslandsCore(grid, rows, cols, row-1, col);
        numIslandsCore(grid, rows, cols, row+1, col);
        numIslandsCore(grid, rows, cols, row, col-1);
        numIslandsCore(grid, rows, cols, row, col+1);
    }
}

int numIslands(vector<vector<char> >& grid)
{
    if(grid.empty()) return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            if(grid[i][j] != '1') continue;
            count++;
            numIslandsCore(grid, rows, cols, i, j);
        }
    }
    return count;
}
int main()
{
    vector<vector<char> > grid;
    vector<char> temp(1, '1');
    grid.push_back(temp);
    cout<<numIslands(grid)<<endl;

    return 0;
}

