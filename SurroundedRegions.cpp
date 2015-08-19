/*************************************************************************
	> File Name: NumberOfIslands.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月03日 星期五 16时11分54秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
void solveCore(vector<vector<char> >& board, const int& rows, const int& cols, int row, int col)
{
    if(row<0 || row>=rows || col<0 || col>=cols) return;
    if(board[row][col] == '1')
    {
        grid[row][col] = 2;
        numIslandsCore(grid, rows, cols, row-1, col);
        numIslandsCore(grid, rows, cols, row+1, col);
        numIslandsCore(grid, rows, cols, row, col-1);
        numIslandsCore(grid, rows, cols, row, col+1);
    }
}

void solve(vector<vector<char> >& board)
{
    if(grid.empty()) return 0;
    int rows = grid.size();
    int cols = grid[0].size();
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            if(grid[i][j] != '1') continue;
            numIslandsCore(grid, rows, cols, i, j);
        }
    }
}
*/

void solve(vector<vector<char> >& board)
{
    if(board.empty()) return;
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool> > visited(rows, vector<bool>(cols, true));
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
            if(board[i][j] == 'X') visited[i][j] = false;
    }
    cout<<"Why"<<endl;
    for(int row = 0; row < rows; ++row)
    {
        for(int col = 0; col < cols; ++col)
        {
            cout<<"row:"<<row<<",col:"<<col<<endl;
            if(!visited[row][col]) continue;
            bool isSurrounded = true;
            queue<pair<int, int> > data;
            data.push({row, col});
            visited[row][col] = false;
            vector<pair<int, int> > position;
            while(!data.empty())
            {
                pair<int, int> posCurrent = data.front();
                int i = posCurrent.first;
                int j = posCurrent.second;
                data.pop();
                position.push_back({i, j});
                if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
                {
                    isSurrounded = false;
                    if(j - 1 >= 0 && visited[i][j-1])
                    {
                        data.push({i, j - 1});
                        visited[i][j - 1] = false;
                    }
                    if(j + 1 < cols && visited[i][j+1])
                    {
                        data.push({i, j + 1});
                        visited[i][j + 1] = false;
                    }
                    if(i - 1 >= 0 && visited[i - 1][j])
                    {
                        data.push({i - 1, j});
                        visited[i - 1][j] = false;
                    }
                    if(i + 1 < rows && visited[i + 1][j])
                    {
                        data.push({i + 1, j});
                        visited[i + 1][j] = false;
                    }
                }
                else 
                {
                    if(visited[i - 1][j]) 
                    {
                        data.push({i - 1, j});
                        visited[i - 1][j] = false;
                    }
                    if(visited[i + 1][j]) 
                    {
                        data.push({i + 1, j});
                        visited[i + 1][j] = false;
                    }
                    if(visited[i][j - 1]) 
                    {
                        data.push({i, j - 1});
                        visited[i][j - 1] = false;
                    }
                    if(visited[i][j + 1]) 
                    {
                        data.push({i, j + 1});
                        visited[i][j + 1] = false;
                    }
                }
            }
            for(int k = 0; k < position.size(); ++k)
            {
                int row = position[k].first;
                int col = position[k].second;
                if(isSurrounded) board[row][col] = 'X';
            }
        }
    }
}

void print(const vector<vector<char> >& board)
{
    for(int i = 0; i < board.size(); ++i)
    {
        for(int j = 0; j < board[i].size(); ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    vector<vector<char> > board(4, vector<char>(4, 'X'));
    board[1][1] = 'o';
    board[1][2] = 'o';
    board[2][2] = 'o';
    board[3][1] = 'o';
    print(board);
    solve(board);
    print(board);

    return 0;
}

