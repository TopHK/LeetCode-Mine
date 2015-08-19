#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<vector<int> >& height, int row)
{
	int sum = 0;
	stack<int> st;
	for(int j=0; j<height[row].size(); ++j)
	{
		if(st.empty() || height[row][j]>height[row][st.top()]) st.push(j);
		else
		{
			int tempIndex = st.top();
			st.pop();
            int tempSum = (st.empty() ? j : (j-st.top()-1)) * height[row][tempIndex];
			sum = max(tempSum, sum);
			j--;
		}
	}
	return sum;
}

void print(const vector<vector<int> >& matrix);
int maximalRectangle(vector<vector<char> >& matrix)
{
    if(matrix.empty()) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> temp(cols+1, 0);
    vector<vector<int> > dp(rows, temp); 
    for(int j=0; j<cols; ++j)
        if(matrix[0][j] == '1') dp[0][j] = 1;
    for(int i=1; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
            if(matrix[i][j] == '1') dp[i][j] += (dp[i-1][j]+1);
    }
    cout<<dp[0][1]<<" "<<dp[1][1]<<endl;
    print(dp);
    int maxArea = 0;
    for(int i=0; i<rows; ++i)
    {
        int tempArea = largestRectangleArea(dp, i);
        cout<<"i:"<<i<<","<<tempArea<<endl;
        maxArea = max(maxArea, tempArea);
    }
    return maxArea;
}

void print(const vector<vector<int> >& matrix)
{
    for(int i=0; i<matrix.size(); ++i)
    {
        for(int j=0; j<matrix[0].size(); ++j)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    char arr1[] = {'0', '1'};
    vector<char> vec(arr1, arr1+sizeof(arr1)/sizeof(char));
    vector<vector<char> > matrix(2, vec);
    
    cout<<maximalRectangle(matrix)<<endl;

    return 0;
}
