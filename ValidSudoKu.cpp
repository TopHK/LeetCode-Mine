class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
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
};
