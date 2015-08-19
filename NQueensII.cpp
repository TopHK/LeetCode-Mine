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
    int numberOfSolutions; 
public:
    void solveNQueensCore(int n, vector<string>& oneSolution)
    {
        int size = oneSolution.size();
        if(size == n)
        {
            numberOfSolutions++;
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

    int totalNQueens(int n)
    {
        vector<string> oneResult;
        numberOfSolutions = 0;
        solveNQueensCore(n, oneResult);
        return numberOfSolutions;
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
    int n = 8;
    Solution sol;
    int number = sol.totalNQueens(n);
    cout<<n<<":"<<number<<endl;
    return 0;
}
