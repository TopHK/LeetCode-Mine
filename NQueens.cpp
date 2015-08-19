/*************************************************************************
	> File Name: NQueens.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月27日 星期六 20时12分49秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution
{
private:
    vector<vector<string> > result;
public:
    void solveNQueensCore(int n, vector<string>& oneSolution)
    {
        int size = oneSolution.size();
        if(size == n)
        {
            result.push_back(oneSolution);
            return;
        }
        for(int i=0; i<n; ++i)
        {
            bool canPlace = true;
            for(int j=0; j<size; ++j)
            {
                string queen = oneSolution[j];
                int posOfQueen = queen.find('Q');
                if(posOfQueen==i || abs(i-posOfQueen)==abs(size-j))
                {
                    canPlace = false;
                    break;
                }
            }
            if(canPlace)
            {
                vector<string> oneSolutionTemp(oneSolution.begin(), oneSolution.end());
                string oneQueue(n, '.');
                oneQueue[i] = 'Q';
                oneSolutionTemp.push_back(oneQueue);
                solveNQueensCore(n, oneSolutionTemp);
            }
        }
    }

    vector<vector<string> > solveNQueens(int n)
    {
        vector<string> oneResult;
        solveNQueensCore(n, oneResult);
        return result;
    }
};

void print(const vector<vector<string> >& result)
{
    for(int i=0; i<result.size(); ++i)
    {
        for(int j=0; j<result[i].size(); ++j)
            cout<<result[i][j]<<endl;
        cout<<endl;
    }
}

int main()
{
    int n = 4;
    Solution sol;
    vector<vector<string> > result = sol.solveNQueens(n);
    print(result);

    return 0;
}
