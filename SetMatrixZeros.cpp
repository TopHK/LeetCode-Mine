/*************************************************************************
	> File Name: SetMatrixZeros.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 14时37分54秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int> >& matrix)
{
    map<int, bool> rowsZero;
    map<int, bool> colsZero;
    int rowsNumber = matrix.size();
    int colsNumber = matrix[0].size();

    for(int i=0; i<rowsNumber; ++i)
    {
        for(int j=0; j<colsNumber; ++j)
        {
            if(matrix[i][j] == 0)
            {
                rowsZero[i] = true;
                colsZero[j] = true;
            }
        }
    }

    for(map<int,bool>::iterator it=rowsZero.begin(); it!=rowsZero.end(); ++it)
    {
        int rowId = it->first;
        for(int j=0; j<colsNumber; ++j) matrix[rowId][j] = 0;
    }
    for(map<int,bool>::iterator it=colsZero.begin(); it!=colsZero.end(); ++it)
    {
        int colId = it->first;
        for(int i=0; i<rowsNumber; ++i) matrix[i][colId] = 0;
    }
}

