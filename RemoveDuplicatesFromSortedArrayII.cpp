/*************************************************************************
	> File Name: RemoveDuplicatesFromSortedArrayII.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月23日 星期二 21时22分49秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int size = nums.size();
    if(size < 3) return size;
    int repeatedNum = nums[0];
    int repeatedCount = 1;
    
    vector<int>::iterator it = nums.begin()+1;
    while(it != nums.end()) 
    {
        int currentNum = *it;
        if(currentNum == repeatedNum) 
        {
            repeatedCount++;
            if(repeatedCount == 3)
            {
                it = nums.erase(it);
                repeatedCount = 2;
                continue;
            }
        }
        else
        {
//            if(repeatedCount > 2) 
//                it = nums.erase(it-repeatedCount+2, it);
            repeatedNum = currentNum;
            repeatedCount = 1;
        }
        it++;
    }
    return nums.size(); 
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 3};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(int));
    cout<<removeDuplicates(nums)<<endl;

    return 0;
}

