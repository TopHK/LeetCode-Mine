/*************************************************************************
	> File Name: SpiralMatrix.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月04日 星期六 16时10分36秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void spiralOrderCore(const vector<vector<int> >& matrix, int row, int col, const int& rows, const int& cols, vector<int>& result)
{
    int leftTopX = row;
    int leftTopY = col;
    int rightTopX = row;
    int rightTopY = cols-col-1;
    int leftBottomX = rows-row-1;
    int leftBottomY = col;
    int rightBottomX = rows-row-1;
    int rightBottomY = cols-col-1;

    if(rightTopY > leftTopY)
    {
        // left to right in the top row
        for(int j=leftTopY; j<=rightTopY; ++j)
            result.push_back(matrix[leftTopX][j]);
        if(rightTopX < rightBottomX)
        {
            for(int i=rightTopX+1; i<=rightBottomX; ++i)
                result.push_back(matrix[i][rightTopY]);
            for(int j=rightBottomY-1; j>=leftBottomY; --j)
                result.push_back(matrix[leftBottomX][j]);
            if(leftBottomX-leftTopX > 1)
            {
                for(int i=leftBottomX-1; i>=leftTopX+1; --i)
                    result.push_back(matrix[i][leftTopY]);
            }
        }
    }
    else 
    {
        for(int i=leftTopX; i<=leftBottomX; ++i)
            result.push_back(matrix[i][leftTopY]);
        return;
    }

}

vector<int> spiralOrder(vector<vector<int> >& matrix)
{
    vector<int> result;
    if(matrix.empty()) return result;
    int rows = matrix.size();
    int cols = matrix[0].size();

    int row = 0;
    int col = 0;
    while(row<((rows+1)>>1) && col<((cols+1)>>1))
    {
        spiralOrderCore(matrix, row, col, rows, cols, result);
        row++;
        col++;
    }
    return result;
}

void print(const vector<int>& matrix)
{
    for(int i=0; i<matrix.size(); ++i)
        cout<<matrix[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr1[] = {1, 2, 3};
    vector<int> vec1(arr1, arr1+sizeof(arr1)/sizeof(int));
    int arr2[] = {4, 5, 6};
    vector<int> vec2(arr2, arr2+sizeof(arr2)/sizeof(int));   
    int arr3[] = {7, 8, 9};
    vector<int> vec3(arr3, arr3+sizeof(arr3)/sizeof(int));
    vector<vector<int> > matrix;
    matrix.push_back(vec1);
    matrix.push_back(vec2);
    matrix.push_back(vec3);
    vector<int> result = spiralOrder(matrix);
    print(result);

    return 0;
}
