/*************************************************************************
	> File Name: MedianOfTwoSortedArrays.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月09日 星期四 19时46分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    double findMedianSortedArraysCore(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if(start1 == size1) return nums2[start2+k-1];
        else if(start2 == size2) return nums1[start1+k-1];
        if(k == 1) return min(nums1[start1], nums2[start2]);
        int len1 = min(k/2, size1-start1);
        int len2 = k-len1;
        if(start2+len2 > size2)
        {
            len2 = size2-start2;
            len1 = k-len2;
        }
        int num1 = nums1[start1+len1-1];
        int num2 = nums2[start2+len2-1];
        if(num1 == num2) return num1;
        else if(num1 < num2)
            return findMedianSortedArraysCore(nums1, start1+len1, nums2, start2, k-len1);
        else 
            return findMedianSortedArraysCore(nums1, start1, nums2, start2+len2, k-len2);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1+size2;
        int k = ((size+1)>>1);
        if(size & 1) return findMedianSortedArraysCore(nums1, 0, nums2, 0, k);
        else return (findMedianSortedArraysCore(nums1, 0, nums2, 0, k) + findMedianSortedArraysCore(nums1, 0, nums2, 0, k+1))*0.5;
    }
};

int main()
{
    Solution sol;
    int arr1[] = {4, 6, 7, 8, 9, 10};
    vector<int> nums1(arr1, arr1+sizeof(arr1)/sizeof(int));
    int arr2[] = {1, 2, 3, 5};
    vector<int> nums2(arr2, arr2+sizeof(arr2)/sizeof(int));
    cout<<sol.findMedianSortedArrays(nums1, nums2)<<endl;

    return 0;
}

