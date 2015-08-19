/*************************************************************************
	> File Name: DungeonGame.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月16日 星期四 16时27分39秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int calculateMinimumHP(vector<vector<int> >& dungeon)
{
    int M = dungeon.size();
    int N = dungeon[0].size();
    vector<vector<int> > dp(M, vector<int>(N, 0));
    dp[M-1][N-1] = 1 - min(0, dungeon[M-1][N-1]);
    for(int i = M-2; i >= 0; --i)
    {
        if(dungeon[i][N-1] >= dp[i+1][N-1]) 
            dp[i][N-1] = 1;
        else dp[i][N-1] = dp[i+1][N-1] - dungeon[i][N-1];
    }
    for(int j = N-2; j >= 0; --j)
    {
        if(dungeon[M-1][j] >= dp[M-1][j+1]) 
            dp[M-1][j] = 1;
        else dp[M-1][j] = dp[M-1][j+1] - dungeon[M-1][j];
    }
    for(int i = M-2; i >= 0; --i)
    {
        for(int j = N-2; j >= 0; --j)       
        {
            int minVal = min(dp[i][j+1], dp[i+1][j]);
            if(dungeon[i][j] >= minVal) 
                dp[i][j] = 1;
            else dp[i][j] = minVal - dungeon[i][j];
        }
    }
    return dp[0][0];
}

int main()
{
    
}

