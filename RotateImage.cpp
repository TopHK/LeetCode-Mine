/*************************************************************************
	> File Name: RotateImage.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月25日 星期四 09时04分35秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void setCircle(vector<vector<int> >& matrix, int row, int col, int size)
{
    int iMin = row;
    int iMax = size-row-1;
    int jMin = iMin;
    int jMax = iMax;

//    for(int j=jMin; j<((size+1)>>1); ++j)
    for(int j=jMin; j<jMax; ++j)
    {
        int temp = matrix[iMin][j];
        int leftValue = matrix[size-j-1][jMin];
        matrix[iMin][j] = leftValue;
        int bottomValue = matrix[iMax][size-j-1];
        matrix[size-j-1][jMin] = bottomValue;
        int rightValue = matrix[j][jMax];
        matrix[iMax][size-j-1] = rightValue;
        matrix[j][jMax] = temp;
    }
}

void rotate(vector<vector<int> >& matrix)
{
    int size = matrix.size();
    int col = 0;
    int row = 0;
    while(row <((size+1)>>1))
        setCircle(matrix, row++, col++, size);
}

void print(const vector<vector<int> >& matrix)
{
    int size = matrix.size();
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int arr[4][4] =
    {
        {1, 2, 3, 8},
        {5, 8, 7, 4},
        {4, 9, 6, 1},
        {2, 4, 3, 7}
    };

    vector<vector<int> > matrix;
//    int arr1[] = {1, 2, 3};
//    vector<int> vec1(arr1, arr1+3);
//    int arr2[] = {5, 8, 7};
//    vector<int> vec2(arr2, arr2+3);
//    int arr3[] = {4, 9, 6};
//    vector<int> vec3(arr3, arr3+3);
//    matrix.push_back(vec1);
//    matrix.push_back(vec2);
//    matrix.push_back(vec3);
    for(int i=0; i<4; ++i)
    {
        vector<int> temp(arr[i], arr[i]+4);
        matrix.push_back(temp);
    }
    rotate(matrix);
    print(matrix);

    return 0;
}
