/*************************************************************************
	> File Name: ImplementingStackUsingQueues.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月25日 星期四 15时59分53秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

class Stack
{
private:
    queue<int> nums1;
    queue<int> nums2;
    int size;
public:
    Stack():size(0){}
    void push(int x)
    {
        if(!nums1.empty() || nums1.empty()&&nums2.empty())
        {
            nums1.push(x);
            size++;
        }
        else
        {
            nums2.push(x);
            size++;
        }
    }

    void pop()
    {
        int i = size;
        int value;
        if(!nums1.empty())
        {
            while(i-- != 1)
            {
                value = nums1.front();
                nums1.pop();
                nums2.push(value);
            }
            nums1.pop();
        }
        else
        {
            while(i-- != 1)
            {
                value = nums2.front();
                nums2.pop();
                nums1.push(value);
            }
            nums2.pop();
        }
        size--;
    }

    int top()
    {
        int value;
        if(!nums1.empty())
        {
            while(!nums1.empty())
            {
                value = nums1.front();
                nums1.pop();
                nums2.push(value);
            }
        }
        else
        {
            while(!nums2.empty())
            {
                value = nums2.front();
                nums2.pop();
                nums1.push(value);
            }
        }
        return value;
    }

    bool empty()
    {
        return size==0;
    }
};

