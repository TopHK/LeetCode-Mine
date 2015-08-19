/*************************************************************************
	> File Name: ContainerWithMostWater.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月21日 星期日 10时26分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height)
{
    int size = height.size();
    if(size < 2) return 0;
    int maxWater = 0;

    for(int i=0; i<=size-2; ++i)
    {
        int tempWater = 0;
        int leftHeight = height[i];
        for(int j=size-1; j>=i+1; j--)
        {
            tempWater = (j-i)*(leftHeight<height[j] ? leftHeight : height[j]);
            if(tempWater > maxWater)
                maxWater = tempWater;
        }
    }
    return maxWater;
}

int maxArea2(vector<int>& height)
{
    int size = height.size();
    int maxWater = 0;
    int left = 0;
    int right = size-1;

    while(left < right)
    {
        maxWater = max(maxWater, min(height[left],height[right])*(right-left));
        height[left]<height[right] ? left++ : right--;
    }
    return maxWater;
}

int main()
{
    int arr[] = {5, 7, 3, 6};
    vector<int> height(arr, arr+sizeof(arr)/sizeof(int));
    cout<<maxArea(height)<<endl;

    return 0;
}

