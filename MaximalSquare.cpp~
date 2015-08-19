#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int>& height)
{
	if(height.empty()) return 0;
	height.push_back(0);
	int sum = 0;
	stack<int> st;
	for(int i=0; i<height.size(); ++i)
	{
		if(st.empty() || height[i]>height[st.top()]) st.push(i);
		else
		{
			int tempIndex = st.top();
			st.pop();
            int tempSum = (st.empty() ? i : (i-st.top()-1)) * height[tempIndex];
			sum = max(tempSum, sum);
			i--;
		}
	}
	return sum;
}

int main()
{
    int arr[] = {4, 2};
    vector<int> height(arr, arr+sizeof(arr)/sizeof(int));
    cout<<largestRectangleArea(height)<<endl;

    return 0;
}
