/*************************************************************************
	> File Name: SudokuSolver.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月11日 星期六 15时29分12秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution 
{
public:
    /*
    bool isValidSudoku(vector<vector<char> >& board) 
    {
        int rows = board.size();
        int cols = rows;

        // for each row
        for(int i=0; i<rows; ++i)
        {
            map<char, bool> charMap;
            for(int j=0; j<cols; ++j)
            {
                if(board[i][j] != '.')
                {
                    if(!charMap.empty() && charMap.find(board[i][j]) != charMap.end()) return false;
                    else charMap[board[i][j]] = true;
                }
            }
        }

        // for each column
        for(int j=0; j<cols; ++j)
        {
            map<char, bool> charMap;
            for(int i=0; i<rows; ++i)
            {
                if(board[i][j] != '.')
                {
                    if(!charMap.empty() && charMap.find(board[i][j]) != charMap.end()) return false;
                    else charMap[board[i][j]] = true;
                }
            }
        }

        // for each 9 sub-boxes of the grid
        for(int subI=0; subI<3; ++subI)
        {
            for(int subJ=0; subJ<3; ++subJ) 
            {
                map<char, bool> charMap;
                int topI = subI*3;
                int topJ = subJ*3;

                for(int m=topI; m<topI+3; ++m)
                {
                    for(int n=topJ; n<topJ+3; ++n)
                    {
                        char temp = board[m][n];
                        if(temp != '.')
                            if(!charMap.empty() && charMap.find(temp)!=charMap.end())
                                return false;
                            else charMap[temp] = true;
                    }
                }
            }
        }
        return true;      
    }
    */

    bool check(const vector<vector<char> >& board, int row, int col)
    {
        char ch = board[row][col];
        for(int j=0; j<9; ++j)
            if(j!=col && ch==board[row][j]) return false;
        for(int i=0; i<9; ++i)
            if(i!=row && ch==board[i][col]) return false;
        int iStart = row/3*3;
        int jStart = col/3*3; 
        for(int i=iStart; i<iStart+3; ++i)
            for(int j=jStart; j<jStart+3; ++j)
                if(!(i==row && j==col) && ch == board[i][j]) return false;
        return true;
    }

    bool solveSudoKuCore(vector<vector<char> >& board)
    {
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j] == '.')
                {
                    for(char ch='1'; ch<='9'; ++ch)
                    {
                        board[i][j] = ch;
                        if(check(board, i, j) && solveSudoKuCore(board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }  
            }
        }
        return true;
    }

    void solveSudoKu(vector<vector<char> >& board)
    {
        solveSudoKuCore(board);
    }
};

void print(const vector<vector<char> >& board)
{
    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    char row1[9] = {'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    vector<char> vec1(row1, row1+9);
    char row2[9] = {'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    vector<char> vec2(row2, row2+9);
    char row3[9] = {'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    vector<char> vec3(row3, row3+9);
    char row4[9] = {'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    vector<char> vec4(row4, row4+9);
    char row5[9] = {'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    vector<char> vec5(row5, row5+9);
    char row6[9] = {'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    vector<char> vec6(row6, row6+9);
    char row7[9] = {'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    vector<char> vec7(row7, row7+9);
    char row8[9] = {'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    vector<char> vec8(row8, row8+9);
    char row9[9] = {'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    vector<char> vec9(row9, row9+9);
    vector<vector<char> > board;
    board.push_back(vec1);
    board.push_back(vec2);
    board.push_back(vec3);
    board.push_back(vec4);
    board.push_back(vec5);
    board.push_back(vec6);
    board.push_back(vec7);
    board.push_back(vec8);
    board.push_back(vec9);
    print(board);
    Solution sol;
    sol.solveSudoKu(board);
    print(board);

    return 0;
}

