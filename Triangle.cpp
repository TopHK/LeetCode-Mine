/*************************************************************************
	> File Name: Triangle.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月27日 星期六 09时19分12秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

int minimumTotal(vector<vector<int> >& triangle)
{
    int total = 0;
    if(triangle.empty()) return 0;
    int rows = triangle.size();

    for(int i=1; i<triangle.size(); ++i)
    {
        for(int j=0; j<triangle[i].size(); ++j)
        {
            if(j == 0) triangle[i][j] += triangle[i-1][j];
            else if(j == triangle[i].size()-1) triangle[i][j] += triangle[i-1][j-1];
            else
            {
                int minTemp = min(triangle[i-1][j-1], triangle[i-1][j]);
                triangle[i][j] += minTemp;
            }
        }
    }

    total = triangle[rows-1][0];
    for(int j=1; j<triangle[rows-1].size(); ++j)
        total = min(total, triangle[rows-1][j]);
    return total;
}

int main()
{
    ifstream ifile("Triangle.txt");
    vector<vector<int> > nums;
    
    int element;
    int rowNum = 1;
    while(ifile>>element)
    {
        vector<int> rowVec;
        rowVec.push_back(element);
        int rowNumTemp = rowNum-1;
        for(int i=0; i<rowNumTemp; ++i)
        {
            ifile>>element;
            rowVec.push_back(element);
        }
        nums.push_back(rowVec);
        rowNum++;
    }

    cout<<minimumTotal(nums)<<endl;
    return 0;
}
